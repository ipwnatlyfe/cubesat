
#define MODEMSERIAL Serial1
#define MODEM_COMMAND_DELAY_MS delay(100)

const int ledSwitch = 14;
unsigned long prevtime = 0;
unsigned long currenttime;
unsigned long time;
char myChar;
String inputString = "";
boolean stringDone = false;


void setup() {
  // put your setup code here, to run once:
    pinMode(ledSwitch, OUTPUT);
  
    Serial.begin(9600);
    MODEMSERIAL.begin(9600);
    MODEM_COMMAND_DELAY_MS;
    delay(2000);
    

    MODEMSERIAL.print("cKG7YTV");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("sc2");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("mKG7YTV");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("ms1");
    MODEM_COMMAND_DELAY_MS;

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(time);
    currenttime = millis();

  getMessage();

  if (stringDone)
  {
    Serial.print(inputString);
    inputString= "";
    stringDone = false;
  }

  if ((currenttime - prevtime) > 10000)
  {
    digitalWrite(ledSwitch, HIGH);
    delay(1000);
    MODEMSERIAL.print("#HI THERE!!!");
    MODEM_COMMAND_DELAY_MS;
    prevtime = time;
    delay(1000);
    digitalWrite(ledSwitch, LOW);
    
  }


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
