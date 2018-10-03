#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <DHT11.h>

hd44780_I2Cexp lcd;
int pin=2;
int pump_pin=13;
int water_time=100;
DHT11 dht11(pin); 

#define RED 3
#define GREEN 4

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(pump_pin,OUTPUT);
  digitalWrite(pump_pin,HIGH);
}

void loop() {
  int humidity = map(analogRead(A0), 0, 1023, 100, 0);
  int err;
  float temp_dht11, humi_dht11;
  lcd.clear();
  if((err=dht11.read(humi_dht11, temp_dht11))==0)
  {
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temp_dht11);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Humi: ");
    lcd.print(humi_dht11);
    lcd.print("%");

    Serial.print("temp: ");
    Serial.print(temp_dht11);
    Serial.print("humi: ");
    Serial.print(humi_dht11);
    Serial.println();
    
  }
  delay(1000); // Refresh
  lcd.clear();

  // Soil humi
    lcd.setCursor(0, 0);
    lcd.print("SoilHumi: ");
    lcd.print(humidity);
    lcd.print("%");
   
  
    lcd.setCursor(0,1);
    if(humidity>35)
    {
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED, LOW);
        lcd.print("I'm OK!");
        delay(1000);
    }
    else
    {
        digitalWrite(GREEN, LOW);
        digitalWrite(RED, HIGH);
        lcd.print("Give me water!");
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Watering On");
        lcd.setCursor(0,1);
        lcd.print("Last: Date");
        digitalWrite(pump_pin,LOW);
        delay(water_time);
        digitalWrite(pump_pin,HIGH);
        delay(1000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Watering Off");
    }
  
  delay(1000);

}
