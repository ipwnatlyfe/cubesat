const int ledPin = 13;
const int ledSwitch = 14;

const long myDelay = 5000;
long previousMillis = 0;
int switchState = LOW;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledSwitch, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();
  

  if((currentMillis - previousMillis) > myDelay)
  {
    
    if (switchState == LOW)
    {
      Serial.println(currentMillis);
      switchState = HIGH;
      Serial.println("HIGH!");
      
    }
    else
    {
      Serial.println(currentMillis);
      switchState = LOW;
      Serial.println("LOW!");
    }
    previousMillis = currentMillis;
    digitalWrite(ledSwitch, switchState);
  }

}
