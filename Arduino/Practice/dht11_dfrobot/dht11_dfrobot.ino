#define dht11_pin 14//Analog port 0 on Arduino Uno
//#define dht11_pin 54 //Analog port 0 on Arduino Mega2560
  
byte read_dht11_dat()
{
  byte i = 0;
  byte result=0;
  for(i=0; i< 8; i++)
  {
    while (!digitalRead(dht11_pin));
    delayMicroseconds(30);
    if (digitalRead(dht11_pin) != 0 )
      bitSet(result, 7-i);
    while (digitalRead(dht11_pin));
  }
  return result;
}
  
  
void setup()
{
  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH);
  Serial.begin(9600);
  Serial.println("Ready");
}
      
void loop()    
{
  byte dht11_dat[5];   
  byte dht11_in;
  byte i;// start condition
       
  digitalWrite(dht11_pin, LOW);
  delay(18);
  digitalWrite(dht11_pin, HIGH);
  delayMicroseconds(1);
  pinMode(dht11_pin, INPUT);
  delayMicroseconds(40);     
    
  if (digitalRead(dht11_pin))
  {
    Serial.println("dht11 start condition 1 not met"); // wait for DHT response signal: LOW
    delay(1000);
    return;
  }
  delayMicroseconds(80);
  if (!digitalRead(dht11_pin))
  {
    Serial.println("dht11 start condition 2 not met");  //wair for second response signal:HIGH
    return;
  }
    
  delayMicroseconds(80);// now ready for data reception
  for (i=0; i<5; i++)
  {  dht11_dat[i] = read_dht11_dat();}  //recieved 40 bits data. Details are described in datasheet
    
  pinMode(dht11_pin, OUTPUT);
  digitalWrite(dht11_pin, HIGH);
  byte dht11_check_sum = dht11_dat[0]+dht11_dat[2];// check check_sum
  if(dht11_dat[4]!= dht11_check_sum)
  {
    Serial.println("DHT11 checksum error");
  }
  Serial.print("Current humdity = ");
  Serial.print(dht11_dat[0], DEC);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(dht11_dat[2], DEC);
  Serial.println("C  ");
  delay(2000); //fresh time
}
