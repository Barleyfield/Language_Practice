#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <DHT11.h>

hd44780_I2Cexp lcd;
int pin=2;
int pump_pin=10;
int moter_pin=7;
int water_volume=100;
DHT11 dht11(pin); 

#define RED 3
#define GREEN 4

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(pump_pin, OUTPUT);
  pinMode(moter_pin,OUTPUT);
  analogWrite(pump_pin,LOW);  // Waterpump off
}

void loop() {
  // put your main code here, to run repeatedly:
  int humidity = map(analogRead(A0), 0, 1023, 100, 0);
  int err;
  float temp_dht11, humi_dht11;
  analogWrite(pump_pin,LOW);
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
  
    
    if(humidity>35)
    {
        lcd.setCursor(0,1);
        analogWrite(pump_pin, LOW);
        doNothing();
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED, LOW);
        lcd.print("I'm OK!");
    }
    else
    {
        lcd.setCursor(0,1);
        digitalWrite(GREEN, LOW);
        digitalWrite(RED, HIGH);
        lcd.print("Waterpump On");
        delay(1000);
        lcd.clear();
        
        lcd.setCursor(0,0);
        lcd.print("Watering");
        lcd.setCursor(0,1);
        lcd.print("MaxLev: ");
        lcd.print(water_volume);
        water();
        /*
        analogWrite(pump_pin,HIGH);
        delay(water_volume);
        analogWrite(pump_pin, LOW);
        */
        delay(1000);
        
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Waterpump Off");
        
        
    }
  
  delay(1000);

}

void water() {
  for(int i = 0; i<360; i++){
    float rad = DEG_TO_RAD * i;
    int sinOut = constrain((sin(rad) * 128) + 128, 0, 255); 
    analogWrite(pump_pin, sinOut);
    delay(15);
  }
}
void doNothing() {}
