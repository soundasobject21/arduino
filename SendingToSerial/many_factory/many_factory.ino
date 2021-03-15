/***********************************************
 Read multiple pins and send to Processing 
 over serial communication

 - assumes you are using analog pins
 - analog pins are used from A0 and up, no gaps
 
***********************************************/

// update with number of sensors
int sensors = 2;
int sensorValue = 0;

void setup() {
  // start serial communications at 9600 baud
  Serial.begin(9600);
}

void loop() {
  // step through the amount of sensors
  for (int i = 0; i < sensors; i++)
  {
    sensorValue = analogRead(i);
    // print the value for pin i
    Serial.print(sensorValue);
    // add a separator after the value so we can parse the line in Processing
    Serial.print("\t"); // ASCII control characters for "tab"
  }
  // add line break after all sensors are read
  Serial.println();
  // looks something like "234\t456\t\n"

}
