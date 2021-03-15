/***********************************************
 Read multiple pins and send to Processing 
 over serial communication

 This differs from the other "many" example as it
 forms a custom string for a combination of known
 digital and analog pins.
 
***********************************************/

int knobPin = A0;
int knobValue = 0;

int sensorPin = A1;
int sensorValue = 0;

int buttonPin = 2;
int buttonState = 0;

void setup() {
  // set pinmode for buttonPin since it's using a digital pin
  pinMode(buttonPin, INPUT);
  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // first, read the knob
  knobValue = analogRead(knobPin);
  // print value to serial, followed by a separator
  Serial.print(knobValue);
  Serial.print("\t"); // separator
  
  // second, read the sensor
  sensorValue = analogRead(sensorPin);
  // print value to serial, followed by a separator
  Serial.print(sensorValue);
  Serial.print("\t"); // separator

  // third, read the button
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  Serial.print("\t"); // separator

  // start a new line
  // a single line would be something like "234\t456\t0\t\n"
  Serial.println();

}
