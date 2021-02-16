/*
 * Lesson 8: Part 4: Multitasking "for loops"
 * 
 * Description:
 * This patch demonstrates how to achieve simultaneous 
 * for loops without using a "for ()" statement
 * 
 * Components:
 * - LED: digital pin 10
 * - LED: digital pin 11
 */

// pins
int ledPin1 = 10;
int ledPin2 = 11;

// for loop counters
int i = 0;
int j = 0;

// fade direction
boolean fadeUp1 = true;
boolean fadeUp2 = true;

// led state storage
int ledState1 = LOW;
int ledState2 = LOW;

// store the last time each task was completed
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

// task interval (milliseconds)
long interval1 = 1;
long interval2 = 10;

void setup() {
  // set the LED digital pins as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // get elapsed time - you only need to get this once, even if you have multiple tasks
  unsigned long currentMillis = millis();

  // task 1: if elapsed time matches or surpasses the interval...
  if (currentMillis - previousMillis1 >= interval1) {
    
    // save the last time this matched the schedule
    previousMillis1 = currentMillis;
    
    // do task 1
    analogWrite(ledPin1, i);

    // increment or decrement i
    // and set fade direction at range edges
    if (fadeUp1) {
      i++; // i = i+1;
      if (i == 255) {
        fadeUp1 = false; // if we reached the end, fade in the other direction
      }
    } else {
      i--; // i = i-1;
      if (i == 0) {
        fadeUp1 = true; // if we reached the end, fade in the other direction
      }
    }
    
  } // done checking task 1 schedule

  // task 2: if elapsed time matches or surpasses the interval...
  if (currentMillis - previousMillis2 >= interval2) {
    
    // save the last time this matched the schedule
    previousMillis2 = currentMillis;
    Serial.println(j);
    
    // do task 2
    analogWrite(ledPin2, j);

    if (fadeUp2) {
      j++;
      if (j == 255) {
        fadeUp2 = false;
      }
    } else {
      j--;
      if (j == 0) {
        fadeUp2 = true;
      }
    }
    
  } // done checking task 2 schedule
  
  // loop

}
