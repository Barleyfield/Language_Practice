#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");

}

// http://artra.tistory.com/entry/%EC%95%84%EB%91%90%EC%9D%B4%EB%85%B8-lcd-1602-%ED%99%94%EB%A9%B4-%ED%95%9C%EA%B8%80%EC%9E%90%EB%AC%B8%EC%A0%9C-%ED%95%B4%EA%B2%B0

void loop()
{
}

