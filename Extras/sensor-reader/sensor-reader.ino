/**************************************
 Read a Sensor

 Make sure you know how much power the
 sensor needs in order to function.

 Sensor should be connected to ground
 and appropriate power, and its signal
 should be connected to an analog input
 
**************************************/

int ledPin = 10; // same as pin 13

int sensorPin = A0;     // analog pin because reading a range of numbers
int sensorValue = 0;    // variable for reading the sensor

void setup() {
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program
  // LED gets brighter as ambient light gets lower
  
  sensorValue = analogRead(sensorPin);
  delay(10);

  // map to pwm friendly numbers
  sensorValue = map(sensorValue, 500, 900, 0, 255);

  // constrain to make sure we only get numbers between 0 and 255
  sensorValue = constrain(sensorValue, 0, 255);
  
  // invert the value
  sensorValue = 255 - sensorValue;

  // print out the value
  Serial.println(sensorValue);

  // tell the led what to do
  analogWrite(ledPin, sensorValue);

}
