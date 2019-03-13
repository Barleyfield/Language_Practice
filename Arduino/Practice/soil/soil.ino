#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

#define RED 3
#define GREEN 4

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int humidity = map(analogRead(A0), 0, 1023, 100, 0);
  lcd.clear();

  
    lcd.setCursor(0, 0);
    lcd.print("Humi : ");
    lcd.print(humidity);
    lcd.print("%");
  
    lcd.setCursor(0,1);
    if(humidity>35)
    {
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED, LOW);
        lcd.print("I'm OK!");
    }
    else
    {
        digitalWrite(GREEN, LOW);
        digitalWrite(RED, HIGH);
        lcd.print("Give me water!");
    }
  
  delay(1000);

}
