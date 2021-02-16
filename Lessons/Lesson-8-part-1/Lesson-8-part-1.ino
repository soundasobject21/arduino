/*
 * Lesson 8, Part 1: Blink Without Delay (dynamic)
 * Adapted from Examples > Digital > Blink Without Delay
 * 
 * Description:
 * This patch reads from one analog input 
 * to control the blink rate of one LED.
 * 
 * Components:
 * - LED: digital pin 10
 * - Knob/sensor: analog pin 0
 */

// pins
int ledPin = 10;
int sensorPin = A0;

// led state storage
int ledState = LOW;

// sensor value storage
int sensorValue = 0;

// store the last time the task was completed (use unsigned long for time)
unsigned long previousMillis = 0;

// task interval (milliseconds)
long interval = 0;

void setup() {
  // set the LED digital pins as output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // get elapsed time (note that currentMillis is initialized with each loop)
  unsigned long currentMillis = millis();

  // read the sensor
  sensorValue = analogRead(sensorPin);
  interval = long(sensorValue);

  // if elapsed time matches or surpasses the interval...
  if (currentMillis - previousMillis >= interval) {
    // save the last time this matched the schedule
    previousMillis = currentMillis;

    // do the task (e.g. blink)
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
    // task complete
    
  } // done checking time
  
  // loop
  
}
