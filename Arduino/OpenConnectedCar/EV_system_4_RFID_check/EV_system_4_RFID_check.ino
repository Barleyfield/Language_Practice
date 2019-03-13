// EV Charging System Arduino Code
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();   // Adafruit 숫자 LCD 선언
LiquidCrystal_I2C lcd(0x27,16,2);                 // LCD 선언
const byte ROWS = 4;                              // 키보드 행(rows) 개수
const byte COLS = 4;                              // 키보드 열(columns) 개수
char keys[ROWS][COLS] = {
  /*
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  */
  {'*','7','4','1'},
  {'0','8','5','2'},
  {'#','9','6','3'},
  {'*','C','B','A'}
};
 
byte rowPins[ROWS] = {6, 7, 8, 9};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[COLS] = {5, 4, 3, 2};   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
  // Adafruit LCD 초기화
  #ifndef __AVR_ATtiny85__
    Serial.begin(9600);
    Serial.println("7 Segment Backpack Test");
  #endif
    matrix.begin(0x70);
    
  // Arduino LCD 초기화
  lcd.init();
  lcd.backlight();
}

void loop() {
  // 변수 선언
  char charge_amount_input[4];            // 충전량 char 배열
  int charge_amount = 0;                  // 충전량 int형 
  int charge_amount_input_index = 0;      // 충전량 char 배열 인덱스
  int charge_complete = 0;                // 충전 완료 변수
  int charge_amount_input_complete = 0;   // 충전량 입력 끝 (while 반복문용)
  int charge_increase = 0;                // 충전량 증가량
  int charge_now = 0;                     // 충전량 - 현재
  int fast_or_slow = 0;                   // fast = 1, slow = 0
  int fast_or_slow_input_complete = 0;    // 급속완속 입력 완료 변수 (while 반복문용), A = Fast, B = slow
  int RFID_check_complete = 0;            // 결제 (RFID 카드) 완료 변수
  int money_required = 0;                 // 전기차 최종 충전요금
  int money_fast = 320;                   // 전기차 충전 요금
  int money_slow = 200;                   //  100%=60kW 기준 완충 20,000원
                                          //  완속 = 20,000원, 급속 = 32,000원으로 가정.
  int emergency_stop = 0;                 // 긴급 정지 (0: 정상 종료, 1: 긴급 종료)
  boolean drawDots = true;                // Adafruit LCD 가운데 점 2개 출력용
  uint16_t timer = 0;                     // Adafruit LCD 충전 시 걸리는 시간
  int i=0;                                // for문용 변수

  
  // Adafruit LCD 초기화 (-- -- 상태. 가운데 점 없음)
  matrix.print(10000, DEC);
  matrix.writeDisplay();
                                                                                                                                                                                                                                      
  // 급속완속 충전 선택
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fast or Slow?");
  lcd.setCursor(0,1);
  lcd.print("Input: ");
  while(fast_or_slow_input_complete != 1)
  {
    char key2 = mykeypad.getKey();
    if( (key2 != NO_KEY) && (key2 == 'A' || key2 == 'B') )
    {
      switch(key2)
      {
        case 'A':           // 'A' 키 누르면 급속충전
          fast_or_slow = 1;
          lcd.print("Fast");
          delay(1500);
          fast_or_slow_input_complete = 1;
          break;
         case 'B':         // 'B' 키 누르면 급속충전
          fast_or_slow = 0;
          lcd.print("Slow");
          delay(1500);
          fast_or_slow_input_complete = 1;
          break;
      }
    
    }
  }

  // 충전량 입력
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Charge Amount?");
  lcd.setCursor(0,1);
  lcd.print("(1~100): ");   // 9글자 (0~8)
  
  while(charge_amount_input_complete != 1)
  {
    char key = mykeypad.getKey();
    if((key != NO_KEY) && ( (key >= '0' && key <= '9') ||  (key == '*' || key == '#') ) )
    {
      if(key == '#')  // #키 : 입력 완료
      {
         charge_amount = atoi(charge_amount_input);
         charge_amount_input_complete == 1;
         break;
      }
      else if( (key == '*') || (charge_amount_input_index > 3) )   // *키 또는 인덱스 초과 : 초기화 (다시 입력)
      {
        for(i=0; i<7; i++)                // 충전량 입력하는 화면 지우기
        {
          lcd.setCursor(9+i,1);
          lcd.print(" ");
        }
        for(i=0; i<4; i++)
        {
          charge_amount_input[i] = '\0';  // NULL문자로 배열 초기화
        }
        charge_amount_input_index = 0;    // 인덱스 초기화
        lcd.setCursor(9,1);
        continue;
      }
      else
      {
        charge_amount_input[charge_amount_input_index] = key;
        charge_amount_input_index++;
        lcd.leftToRight();
        lcd.print(key);
      }
    }
  }

  // RFID 카드로 결제
  if(fast_or_slow == 1)   // 급속/완속에 따른 금액 설정
  {
    money_required = money_fast * charge_amount;
  }
  else
  {
    money_required = money_slow * charge_amount;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Put in your card");
  lcd.setCursor(0,1);
  lcd.print("Pay: ");
  lcd.print(money_required);
  while(RFID_check_complete != 1)
  {
    char key3 = mykeypad.getKey();
    if(key3 != NO_KEY)
    {
      if(key3 == '#')
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Pay OK!");
        lcd.setCursor(0,1);
        lcd.print("Charge Start");
        delay(1500);
        RFID_check_complete = 1;
        break;
      }
    }
  }
  

  // 급속/완속과 충전량 설정에 따른 변수 설정
  if(fast_or_slow == 1)
  {
    charge_increase = 10;
    timer = charge_amount/charge_increase;
  }
  else
  {
    charge_increase = 3;
    timer = charge_amount/charge_increase;
  }


  // 충전 시작
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("To: ");  // 4글자
  lcd.print(charge_amount);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Now: "); // 5글자
  lcd.setCursor(8,1);
  lcd.print("%");
  while(charge_complete != 1)
  {
    char emergency_button = mykeypad.getKey();
    if(emergency_button != NO_KEY)
    {
      if(emergency_button == 'C')    // 비상버튼 'A'를 누르면 강제 반복문 탈출
      {
         charge_complete = 1;
         emergency_stop = 1;
         break;
      }
    }
    if( (charge_now >= charge_amount) || (timer < 0) )
    {
      // Adafruit LCD 00:00으로 초기화
      matrix.writeDigitNum(0, 0, drawDots);
      matrix.writeDigitNum(1, 0, drawDots);
      matrix.drawColon(drawDots);
      matrix.writeDigitNum(3, 0, drawDots);
      matrix.writeDigitNum(4, 0, drawDots);
      matrix.writeDisplay();
      charge_complete = 1;
      break;
    }
    // 타이머 표시
    if(timer % 100 == 0)
    {
      matrix.writeDigitNum(0, (timer / 1000), drawDots);
      matrix.writeDigitNum(1, (timer / 100) % 10, drawDots);
      matrix.drawColon(drawDots);
      matrix.writeDigitNum(3, (timer % 100) / 10 , drawDots);
      matrix.writeDigitNum(4, timer % 10, drawDots);
      timer = timer - 41;
      matrix.writeDisplay();
    }
    else
    {
      matrix.writeDigitNum(0, (timer / 1000), drawDots);
      matrix.writeDigitNum(1, (timer / 100) % 10, drawDots);
      matrix.drawColon(drawDots);
      matrix.writeDigitNum(3, (timer / 10) % 10, drawDots);
      matrix.writeDigitNum(4, timer % 10, drawDots); 
      timer--;
      matrix.writeDisplay();
    }

    // 충전량 표시
    lcd.setCursor(5,1);
    lcd.print(charge_now);
    delay(998);
    charge_now = charge_now + charge_increase;
  }



  if(emergency_stop == 1)
  {      // 비상 정지
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Emergency Stop!");
    delay(1500);
  }
  else
  {     // 충전 정상 완료
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Charge OK!");
    lcd.setCursor(0,1);
    lcd.print("Please Unplug");
    delay(2500);
  }
  

  

}
