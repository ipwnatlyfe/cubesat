const int PTTpin = 12;
const int POWERPIN = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(PTTpin, OUTPUT);
  pinMode(POWERPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();
  Serial.println(currentMillis);
  delay(200);
  if((currentMillis > 10000) && (currentMillis < 20000))
  {
    digitalWrite(POWERPIN, HIGH);
    Serial.println("WENT HIGH!!!");
  }
  else
  {
    digitalWrite(POWERPIN, LOW);
  }


  
  /*
  if((currentMillis > 5000) && (currentMillis < 10000))
  {
    digitalWrite(PTTpin, HIGH);
    Serial.println("WENT HIGH!!!");
  }
  else
  {
    digitalWrite(PTTpin, LOW);
  }
  */
  /*
  if((currentMillis > 5000) && (currentMillis < 5500))
  {
    digitalWrite(PTTpin, LOW);
    Serial.println("Went Low!");
  }
  else
  {
    digitalWrite(PTTpin, HIGH);
  }
  */

}
