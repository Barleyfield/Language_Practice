// EV Charging System Arduino Code
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2); 
const byte ROWS = 4;    // 행(rows) 개수
const byte COLS = 4;    // 열(columns) 개수
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
 
byte rowPins[ROWS] = {6, 7, 8, 9};   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
byte colPins[COLS] = {5, 4, 3, 2};   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
  // put your setup code here, to run once:
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
  int fast_or_slow_input_complete = 0;    // 급속완속 입력 끝 (while 반복문용), A = Fast, B = slow
  int i=0;                                // for문용 변수

                                                                                                                                                                                                                                      

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
        case 'A':
          fast_or_slow = 1;
          lcd.print("Fast");
          delay(1500);
          fast_or_slow_input_complete = 1;
          break;
         case 'B':
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
      else if(key == '*')   // *키 : 초기화 (다시 입력)
      {
        for(i=0; i<3; i++)                // 화면 지우기
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

  // 급속/완속과 충전량 설정에 따른 변수 설정
  if(fast_or_slow == 1)
  {
    charge_increase = 10;
  }
  else
  {
    charge_increase = 3;
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
    if( (charge_now >= charge_amount) )
    {
      charge_complete = 1;
      break;
    }
    lcd.setCursor(5,1);
    lcd.print(charge_now);
    delay(1500);
    charge_now = charge_now + charge_increase;
  }


  // 충전 완료
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Charge OK!");
  lcd.setCursor(0,1);
  lcd.print("Please Unplug");
  delay(2500);
  
 


  

}
