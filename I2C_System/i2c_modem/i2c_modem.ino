#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}


// code taken from example code by Nicholas Zambetti <http://www.zambetti.com>
void receiveEvent(int howMany) {
  while (1 < Wire.available()) {  // loop through all but the last
    char c = Wire.read();         // receive byte as a character
    Serial.print(c);              // print the char    
  }
  int x = Wire.read();            // receive byte as an integer
  Serial.println(x);               // print the integer
}

