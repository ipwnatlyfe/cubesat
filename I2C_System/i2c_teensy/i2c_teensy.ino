#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>


#define BNO055_SAMPLERATE_DELAY_MS (500)
#define MODEM_ADDRESS 8

Adafruit_BNO055 bno = Adafruit_BNO055();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Orientation Sensor Raw Data Test");
  Serial.println("");

  /* Initialise the sensor */
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  delay(1000);

  /* Display the current temperature */
  int8_t temp = bno.getTemp();
  Serial.print("Current Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  Serial.println("");

  bno.setExtCrystalUse(true);

  Serial.println("Calibration status values: 0=uncalibrated, 3=fully calibrated");
  
  Wire.begin(); // join i2c bus (address optional for master)
  
}
int8_t temp;
byte x = 0;
byte y = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sent: ");
  Serial.print(x);
  Serial.print("\n");
  Wire.beginTransmission(MODEM_ADDRESS); // transmit to modem
  Wire.write("Test from teensy: ");
  Wire.write(x);
  Wire.endTransmission(); // stop transmitting

  x++;
  delay(500);

  Serial.println("Request data from Slave: ");
  Wire.requestFrom(MODEM_ADDRESS, 16);

  int bytes = Wire.available();
  Serial.print("Slave sent ");
  Serial.print(bytes);
  Serial.print("bytes of information\n");
  for(int i = 0; i< bytes; i++)
  {
    y = Wire.read();
    Serial.print("Slave sent: ");
    Serial.print(y);
    Serial.print("\n");
  }
  
  
  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  temp = bno.getTemp();
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("\n");
  
    /* Display the floating point data */
  Serial.print("X: ");
  Serial.print(euler.x());
  Serial.print(" Y: ");
  Serial.print(euler.y());
  Serial.print(" Z: ");
  Serial.print(euler.z());
  Serial.print("\t\t");

  uint8_t system, gyro, accel, mag = 0;
  bno.getCalibration(&system, &gyro, &accel, &mag);
  Serial.print("CALIBRATION: Sys=");
  Serial.print(system, DEC);
  Serial.print(" Gyro=");
  Serial.print(gyro, DEC);
  Serial.print(" Accel=");
  Serial.print(accel, DEC);
  Serial.print(" Mag=");
  Serial.println(mag, DEC);

  delay(BNO055_SAMPLERATE_DELAY_MS);
  
}


