float temperature;  
int reading;  
int lm35Pin = A0;

void setup()  
{
    analogReference(INTERNAL);
    Serial.begin(9600);
}

void loop()  
{
    reading = analogRead(lm35Pin);
    temperature = reading / 9.31;
    
    Serial.println(temperature);
    delay(1000);
}



//출처: http://gent.tistory.com/80 [젠트의 프로그래밍 세상]
