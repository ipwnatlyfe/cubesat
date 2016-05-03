#include <Wire.h>

#define MODEMSERIAL Serial1
#define MODEM_COMMAND_DELAY_MS (100)

const int ledSwitch = 14;
unsigned long previousMillis = 0;
unsigned long currentMillis;
unsigned long time;
char myChar;
String inputString = "";
boolean stringDone = false;



void setup() {
  // put your setup code here, to run once:
    pinMode(ledSwitch, OUTPUT);
  
    Serial.begin(9600);
    MODEMSERIAL.begin(9600);

    MODEMSERIAL.print("cKG9YTV");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("sc2");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("mKG9YTV");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("ms1");
    MODEM_COMMAND_DELAY_MS;

    digitalWrite(ledSwitch, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();

  if((currentMillis - previousMillis) > 10000)
  {
    MODEMSERIAL.print("#HI THERE!!!");
    Serial.println("Message Sent!");
    MODEM_COMMAND_DELAY_MS;
    previousMillis = currentMillis;
  }

  

}
