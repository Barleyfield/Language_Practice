#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <DHT11.h>
#include <Time.h>
#include <TimeAlarms.h>

hd44780_I2Cexp lcd;
int is_watered=1;   // Check if arduino already gave water
int pin=2;
int pump_pin=5;
int water_time=5000;
int prev_time=0;    // previous watered time
DHT11 dht11(pin); 

// Switch declaration & Settings
int sw = 6;
int led_r_1 = 7;
int led_r_2 = 8; 
int led_b = 9;
int led_w = 10;
int led_num_check = 1;
int reading;
int led_priority = 0;

long time = 0;
long debounce = 3000;  // Switch debouncing (Removing multiple inputs) 
// -------

#define RED 3
#define GREEN 4
#define TIME_GAP_HOUR 3    // Time gap = 3 hrs
#define TIME_GAP_MINUTE 1   // Time gap = 1 minute
#define TIME_GAP_SECOND 30 // Time gap = 30 secs
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(pump_pin, OUTPUT);
  pinMode(led_r_1, OUTPUT);
  pinMode(led_r_2, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(led_w, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  digitalWrite(pump_pin,LOW);  // Waterpump off
  setTime(15,12,0,30,5,18);
  prev_time = minute();   // Set prev_time on current minute
  
}

void loop() {
  
  int humidity = map(analogRead(A0), 0, 1023, 100, 0);
  int err;
  float temp_dht11, humi_dht11;
  reading = digitalRead(sw);
  Led_On();
 
    digitalWrite(pump_pin,LOW);
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
      Serial.print(" ");
      Serial.print("humi: ");
      Serial.print(humi_dht11);
      Serial.println();
      
    }
    delay(1000); // Refresh
    lcd.clear();
    Led_On();
  
    // Soil humi
      lcd.setCursor(0, 0);
      lcd.print("SoilHumi: ");
      lcd.print(humidity);
      lcd.print("%");
      Serial.print("Soil Humidity: ");
      Serial.print(humidity);
      Serial.println(); 

      if(humidity>45)
      {
          lcd.setCursor(0,1);
          digitalWrite(pump_pin, LOW);
          digitalWrite(GREEN, HIGH);
          digitalWrite(RED, LOW);
          lcd.print("I'm OK!");
          
      }
      else
      {
         // Water Switch
         // Set is_watered to 1 if conditions are satisfied
         if( (minute()-prev_time)>=TIME_GAP_MINUTE)
         {
            is_watered=1;
         }
         
        if(is_watered==1)
        {
          lcd.setCursor(0,1);
          digitalWrite(GREEN, LOW);
          digitalWrite(RED, HIGH);
          lcd.print("Waterpump On");
          delay(1000);
          lcd.clear();
          
          Led_On();
          
          lcd.setCursor(0,0);
          lcd.print("Watering");
          lcd.setCursor(0,1);
          lcd.print("Elapsed: ");
          lcd.print(water_time/1000);
          lcd.print("s");
          digitalWrite(pump_pin,HIGH);
          delay(water_time);
          digitalWrite(pump_pin,LOW);
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Waterpump Off");
          is_watered=0;
          prev_time = minute();
      
        }
        else
        {
          digitalWrite(GREEN, HIGH);
          digitalWrite(RED, LOW);
          lcd.setCursor(0,1);
          lcd.print("Already Watered");
          delay(1000);
          Led_On();
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Already Watered");
          lcd.setCursor(0,1);
          lcd.print("Prev: ");
          lcd.print(minute()-prev_time);
          
  
        }
        
          
      }
      delay(1000);
       Led_On();
      lcd.clear();
      
 
}

void Led_On()
{
  // While switch is pushed
  if(reading==LOW && (millis()-time)>debounce)
  {
    if( (led_num_check % 10 == 1) || (led_num_check % 10 == 2) )
    {
      digitalWrite(led_r_1, HIGH);
      digitalWrite(led_r_2, HIGH);
      digitalWrite(led_b, LOW);
      digitalWrite(led_w, LOW);
      Serial.println("LED RED ON");
      led_num_check++;
    }
    else if( (led_num_check % 10 == 3) || (led_num_check % 10 == 4) )
    {
      digitalWrite(led_r_1, LOW);
      digitalWrite(led_r_2, LOW);
      digitalWrite(led_b, HIGH);
      digitalWrite(led_w, LOW);
      Serial.println("LED BLUE ON");
      led_num_check++;
    }
    else if( (led_num_check % 10 == 5) || (led_num_check % 10 == 6) )
    {
      digitalWrite(led_r_1, LOW);
      digitalWrite(led_r_2, LOW);
      digitalWrite(led_b, LOW);
      digitalWrite(led_w, HIGH);
      Serial.println("LED WHITE ON");
      led_num_check++;
    }
    else if( (led_num_check % 10 == 7) || (led_num_check % 10 == 8) )
    {
      digitalWrite(led_r_1, HIGH);
      digitalWrite(led_r_2, HIGH);
      digitalWrite(led_b, HIGH);
      digitalWrite(led_w, HIGH);
      Serial.println("LED ALL ON");
      led_num_check++;
    }
    else
    {
      digitalWrite(led_r_1, LOW);
      digitalWrite(led_r_2, LOW);
      digitalWrite(led_b, LOW);
      digitalWrite(led_w, LOW);
      Serial.println("LED ALL OFF");
      led_num_check++;
    }
    time = millis();

  }
}


