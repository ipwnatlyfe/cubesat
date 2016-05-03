#define HWSERIAL Serial1

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    HWSERIAL.begin(9600);
}

void loop() {
int incomingByte;
  
  if(Serial.available() > 0)
  {
    incomingByte = Serial.read();
    Serial.print("USB Received: ");
    Serial.println(incomingByte, DEC);
    HWSERIAL.print("USB Received:");
    HWSERIAL.println(incomingByte,DEC);
    
  }

//  if(HWSERIAL.available() > 0) 
//  {
//    incomingByte = HWSERIAL.read();
//    Serial.print("UART received: ");
//    Serial.println(incomingByte, DEC);
//    HWSERIAL.print("UART received:");
//    HWSERIAL.println(incomingByte, DEC);
//  }
  
  // put your main code here, to run repeatedly:
//  Serial.println("#PLZPLZ WORK");
//
//  
//  Serial.println("#Hi there!");

}
