#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


#define MODEMSERIAL Serial1
#define BNO055_SAMERATE_DELAY_MS (100)
#define MODEM_COMMAND_DELAY_MS (100)

Adafruit_BNO055 bno = Adafruit_BNO055();

unsigned long time;
char myChar;
String inputString = "";
boolean stringDone = false;


void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
    MODEMSERIAL.begin(9600);

    Serial1.print("cKG9YTV");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("sc2");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("mKG9YTV");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("ms1");
    MODEM_COMMAND_DELAY_MS;

}

void loop() {
  // put your main code here, to run repeatedly:

    time = millis();

  getMessage();

  if (stringDone)
  {
    Serial.print(inputString);
    inputString= "";
    stringDone = false;
  }

  void getMessage() {
  while (MODEMSERIAL.available()){
    myChar = MODEMSERIAL.read();
    inputString += myChar;

    if (myChar == '\n')
    {
      stringDone = true;
    }
  }
}


}
