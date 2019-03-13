#define BUTTON 6
#define LED 12
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON)=LOW)
  {
    if(flag==0)
    {
      digitalWrite(LED, HIGH);
      flag=1;
    }
    else
    {
      digitalWrite(LED, LOW);
      flag = 0;
    }
    while(digitalRead(BUTTON)==LOW);
  }

}
