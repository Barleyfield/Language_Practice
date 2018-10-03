#include <SoftwareSerial.h>
SoftwareSerial BTSerial(3,2);
const int Buzzer=4;
const int trigPin=5;
const int echoPin=6;
const int led_red = 10;
const int led_green = 13;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, HIGH);
 
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  
  int distance;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  distance=pulseIn(echoPin, HIGH)/58.2;
  Serial.print(distance);
  Serial.println(" cm");
 
  if(distance <= 10)
  {
    tone(Buzzer, 261);
    digitalWrite(led_red, HIGH);
    digitalWrite(led_green, LOW);
  }
  else
  {
    noTone(Buzzer);
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
  }
  delay(10);
  
}
