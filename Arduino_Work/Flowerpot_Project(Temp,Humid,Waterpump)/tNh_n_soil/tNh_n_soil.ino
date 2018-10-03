#include <Wire.h>
#include <hd44780.h>
#include <LiquidCrystal_I2C.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <DHT11.h>

LiquidCrystal_I2C lcd_dht11(0x27,16,2);  
hd44780_I2Cexp lcd;

int pin=5;
DHT11 dht11(pin);
#define RED 3
#define GREEN 4

void setup() {
  // put your setup code here, to run once:
  lcd_dht11.init();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  int err;
  float temp_dht11, humi_dht11;
  // put your main code here, to run repeatedly:
  int humidity = map(analogRead(A0), 0, 1023, 100, 0);
  lcd.clear();
  if((err=dht11.read(humi_dht11, temp_dht11))==0)
  {
    // DHT11 temp, humi
    lcd_dht11.backlight();
    lcd_dht11.display();
    lcd_dht11.setCursor(0,0);
    lcd_dht11.print("Temp: ");
    lcd_dht11.print(temp_dht11);
    lcd_dht11.setCursor(0,1);
    lcd_dht11.print("Humi: ");
    lcd_dht11.print(humi_dht11);
 
    Serial.print("Temp: ");
    Serial.print(temp_dht11);
    Serial.print("Humi: ");
    Serial.print(humi_dht11);
    Serial.println();
    lcd_dht11.clear();
    delay(1000);


    // Soil Humi
    
    lcd.setCursor(0,0);
    lcd.print("Soil Humi : ");
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
  }
  else
  {
    lcd_dht11.backlight();
    lcd_dht11.display();
    lcd_dht11.print("ERROR NO.: ");
    lcd_dht11.print(err); 
  }
  
  delay(1000);

}
