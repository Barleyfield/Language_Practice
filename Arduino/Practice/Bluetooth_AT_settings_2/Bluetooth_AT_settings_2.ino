#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX

void setup()
{
  //Serial.begin(9600);
  //Serial.begin(57600);
  Serial.begin(4800);
  Serial.println("Goodnight moon!");

  mySerial.begin(4800);
  //mySerial.begin(57600);
  //mySerial.begin(115200);    //if you change the baud and want to re-run this sketch, make sure this baud rate matches the new rate.

  //mySerial.print("AT+PIN1234"); // Set pin to 1234  was 1342
  //delay(1000);

  //mySerial.print("AT+NAMEJY-MCU-HC06"); // Set the name to JY-MCU-HC06
  //delay(1000);

  //mySerial.print("AT+BAUD4"); // Set baudrate to 9600
  //mySerial.print("AT+BAUD7"); // Set baudrate to 57600

}

void loop() // run over and over
{
  if (mySerial.available())
  Serial.write(mySerial.read());
  if (Serial.available())
  mySerial.write(Serial.read());
}
