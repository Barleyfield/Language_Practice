int pump_pin = 3;
int sw_pin=4;
int water_volumn=750;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pump_pin,OUTPUT); 
  pinMode(sw_pin,INPUT); 

  digitalWrite(pump_pin,HIGH); 
  delay(100);
  
  Serial.println("pump off");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(sw_pin) == LOW)
  {
    Serial.println("pump on");
    
    digitalWrite(pump_pin, LOW); 
    delay(water_volumn);
    digitalWrite(pump_pin, HIGH); 
    
    delay(100);
    Serial.println("pump off");
  }
  
  delay(100); 
}


