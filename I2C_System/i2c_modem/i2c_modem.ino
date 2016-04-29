#include <Wire.h>

#define MODEM_ADDRESS 8

void setup() {
  // put your setup code here, to run once:
  Wire.begin(MODEM_ADDRESS);    // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output

}

byte y = 200;
void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
 
}

void requestEvent()
{
  Serial.print("Request from Master. Sending: ");
  Serial.print("pew pew pew");
  Serial.print("\n");

  Wire.write("pew");
  y++;
}


// code taken from example code by Nicholas Zambetti <http://www.zambetti.com>
void receiveEvent(int howMany) {
  while (1 < Wire.available()) {    // loop through all but the last
    char c = Wire.read();           // receive byte as a character
    Serial.print(c);                // print the char    
  }
  int x = Wire.read();              // receive byte as an integer
  Serial.println(x);                // print the integer
  
  
}

