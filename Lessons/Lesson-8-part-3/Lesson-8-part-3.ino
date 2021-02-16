/*
 * Lesson 8, Part 3: Multitasking
 * 
 * Description:
 * This patch reads from two analog inputs to
 * control the blink rate of two different LEDs
 * 
 * Components:
 * - LED: digital pin 10
 * - LED: digital pin 11
 * - Knob/sensor: analog pin 0
 * - Knob/sensor: analog pin 1
 */

// pins
int ledPin1 = 10;
int ledPin2 = 11;
int sensorPin1 = A0;
int sensorPin2 = A1;

// led state storage
int ledState1 = LOW;
int ledState2 = LOW;

// sensor value storage
int sensorValue1 = 0;
int sensorValue2 = 0;

// store the last time each task was completed
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

// task interval (milliseconds)
long interval1 = 0;
long interval2 = 0;

void setup() {
  // set the LED digital pins as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // get elapsed time - you only need to get this once, even if you have multiple tasks
  unsigned long currentMillis = millis();

  // read the sensor for task 1
  sensorValue1 = analogRead(sensorPin1);
  interval1 = long(sensorValue1);

  // read the sensor for task 2
  sensorValue2 = analogRead(sensorPin2);
  Serial.println(sensorValue2);
  interval2 = long(sensorValue2);

  // task 1: if elapsed time matches or surpasses the interval...
  if (currentMillis - previousMillis1 >= interval1) {
    // save the last time this matched the schedule
    previousMillis1 = currentMillis;

    // do task 1
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
    digitalWrite(ledPin1, ledState1);
    // task 1 complete
    
  } // done checking task 1 schedule

  // task 2: if elapsed time matches or surpasses the interval...
  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time this matched the schedule
    previousMillis2 = currentMillis;

    // do task 2
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
    digitalWrite(ledPin2, ledState2);
    // task 2 complete
    
  } // done checking task 2 schedule
  
  // loop
  
}
