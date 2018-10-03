void setup() {
  pinMode(8, OUTPUT);
 // pinMode(9,OUTPUT);
  //pinMode(12, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  digitalWrite(8,HIGH);
  //digitalWrite(9,HIGH);
 // digitalWrite(12,LOW);
  delay(1000);
  //digitalWrite(12,HIGH);
  digitalWrite(8,LOW);
 // digitalWrite(9,LOW);
  delay(1000);

}
