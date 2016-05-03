#define MODEMSERIAL Serial1
#define MODEM_COMMAND_DELAY_MS delay(100)

unsigned long time;
unsigned long previousMillis = 0;
unsigned long currentMillis;
char myChar;
String inputString = "";
boolean stringDone = false;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    MODEMSERIAL.begin(9600);

    Serial1.print("cKG7YTV");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("sc2");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("mKG7YTV");
    MODEM_COMMAND_DELAY_MS;
    Serial1.print("ms1");
    MODEM_COMMAND_DELAY_MS;

}

void loop() {
  // put your main code here, to run repeatedly:
  currentMillis = millis();

    getMessage();

  if (stringDone)
  {
    Serial.print(inputString);
    inputString= "";
    stringDone = false;
  }

  if ((currentMillis - previousMillis) > 10000)
  {
    MODEMSERIAL.print("hi");
    Serial.print("MessageSent!");
    MODEM_COMMAND_DELAY_MS;
    MODEMSERIAL.print("#Hi!!");
    previousMillis = currentMillis;
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
