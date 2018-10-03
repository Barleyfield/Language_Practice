int led = 2;
int sw = 10;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(sw)==LOW)
  {
    digitalWrite(led, HIGH);
    Serial.println("SW ON");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("SW OFF");
  }

}
