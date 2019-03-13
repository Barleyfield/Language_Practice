int sw = 2;
int led_r_1 = 3;
int led_r_2 = 4;
int led_b = 5;
int led_w = 6;
int led_num_check = 1;
int reading;


long time = 0;
long debounce = 600;

void setup() {
  
  Serial.begin(9600);
  pinMode(led_r_1, OUTPUT);
  pinMode(led_r_2, OUTPUT);
  pinMode(led_b, OUTPUT);
  pinMode(led_w, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
 
}

void loop() {
  reading = digitalRead(sw);
  
  if(digitalRead(sw)==LOW && millis()-time > debounce)
  {
    if(led_num_check % 5 == 1)
    {
      digitalWrite(led_r_1, HIGH);
      digitalWrite(led_r_2, HIGH);
      digitalWrite(led_b, LOW);
      digitalWrite(led_w, LOW);
      Serial.println("LED RED ON");
      led_num_check++;
    }
    else if(led_num_check % 5 == 2)
    {
      digitalWrite(led_r_1, LOW);
      digitalWrite(led_r_2, LOW);
      digitalWrite(led_b, HIGH);
      digitalWrite(led_w, LOW);
      Serial.println("LED BLUE ON");
      led_num_check++;
    }
    else if(led_num_check % 5 == 3)
    {
      digitalWrite(led_r_1, LOW);
      digitalWrite(led_r_2, LOW);
      digitalWrite(led_b, LOW);
      digitalWrite(led_w, HIGH);
      Serial.println("LED WHITE ON");
      led_num_check++;
    }
    else if(led_num_check % 5 == 4)
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
  
  /*
  else
  {
    digitalWrite(led, LOW);
    Serial.println("SW OFF");
  }
  */

}
