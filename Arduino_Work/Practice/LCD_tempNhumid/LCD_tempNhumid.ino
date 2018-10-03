#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>
 
//LCD 설정
LiquidCrystal_I2C lcd(0x27,16,2);  
 
//온습도센서 연결설정
int pin=2;
DHT11 dht11(pin); 
 
void setup()
{
  lcd.init();
  Serial.begin(9600);
}
 
void loop()
{
  int err;
  float temp, humi;
  if((err=dht11.read(humi, temp))==0)
  {
    lcd.backlight();
    lcd.display();
    lcd.print("TEM: ");
    lcd.print(temp);
    lcd.setCursor(0,1);
    lcd.print("HUM: ");
    lcd.print(humi);
 
    Serial.print("temp: ");
    Serial.print(temp);
    Serial.print("humi: ");
    Serial.print(humi);
    Serial.println();
  }
  else
  {
    lcd.backlight();
    lcd.display();
    lcd.print("ERROR NO.: ");
    lcd.print(err);
  }
  delay(3000); //10초마다 Refresh
  lcd.clear();
}



//출처: http://deneb21.tistory.com/235 [Do It Yourself!]
