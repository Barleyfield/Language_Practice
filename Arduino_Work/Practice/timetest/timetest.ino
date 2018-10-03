#include <Time.h>
#include <TimeAlarms.h>
#include <LiquidCrystal.h>
//#include <hd44780.h>
//#include <hd44780ioClass/hd44780_I2Cexp.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  setTime(14,29,0,1,11,11);
  Alarm.timerRepeat(15, Repeats);            // timer for every 15 seconds   
}

void Repeats() {
    lcd.blink();
    delay(2000);
}

void  loop(){ 
  digitalClockDisplay();
  Alarm.delay(1000); // wait one second between clock display
}

void digitalClockDisplay()
{
 
  lcd.begin(16, 3);
  lcd.print(year());
  lcd.print(".");
  lcd.print(month());
  lcd.print(".");
  lcd.print(day());

  lcd.setCursor(0, 1);
  lcd.print(hour());
  printDigits(minute());
  printDigits(second());
}

void printDigits(int digits)
{
  lcd.print(":");
  if(digits < 10)
    lcd.print('0');
  lcd.print(digits);
}




