/**************************************
 Read a pin and send to Processing 
 over serial communication
 
**************************************/

int sensorPin = A0;     // analog pin because reading a range of numbers
int sensorValue = 0;    // variable to store sensor value

void setup() {
  // connect to serial port at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // read the sensor
  sensorValue = analogRead(sensorPin);
  // send value to serial port
  Serial.println(sensorValue);
}
