/**************************************
  Lesson 7: Using Conditionals: Toggle

  Additional materials
  - 1 10K ohm resistor
  - 1 momentary button (https://www.adafruit.com/product/1119)

**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

int buttonPin = 7;    // digital pin because binary (on/off)
int buttonState = 0;  // variable for reading the switch

int toggleBtnPin = 2;       // digital pin because binary (on/off)
int toggleBtnState = 0;     // variable for reading the button
int lastToggleBtnState = 0; // place to store the previous state of the toggleBtn

bool toggleState = true;    // true/false value thate toggles between states

void setup() {
  // put your setup code here, which runs once

  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // set digital pins as inputs:
  pinMode(buttonPin, INPUT);
  pinMode(toggleBtnPin, INPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);

}

void loop() {
  // main program goes here

  // ---- TURN BUTTON INTO TOGGLE ----------------------------------  
  
  // read the toggle button
  toggleBtnState = digitalRead(toggleBtnPin);

  // if toggle button has been pressed...
  if (toggleBtnState != lastToggleBtnState) {
    // only if the new state is the press (not the release)
    if (toggleBtnState == 1) {
      // flip the toggle
      toggleState = !toggleState;
    }
    // reset lastToggleBtnState to save the current state
    lastToggleBtnState = toggleBtnState;
  }

  Serial.print("Toggle: ");
  Serial.println(toggleState);

  if (toggleState) {
    // toggled on
    digitalWrite(ledPin, HIGH);           // turn the ledPin on

  } else {
    // toggled off
    // so check if the other button is pressed
    buttonState = digitalRead(buttonPin);
    Serial.print("Button: ");
    Serial.println(buttonState);

    if (buttonState == 1) {
      // button is pressed so read the value of the knob
      knobValue = analogRead(knobPin);

      if (knobValue < 300) {
        // button is pressed and knobValue is less than 300
        knobValue = analogRead(knobPin);

        digitalWrite(ledPin, HIGH);       // turn the ledPin on
        Serial.print("LedOn, Knob=");
        Serial.println(knobValue);
        delay(knobValue);                 // stop the program for <knobValue> ms

        knobValue = analogRead(knobPin);

        digitalWrite(ledPin, LOW);        // turn the ledPin off
        Serial.print("LedOff, Knob=");
        Serial.println(knobValue);
        delay(knobValue);                 // stop the program for <knobValue> ms

      } else {
        // button is pressed and knobValue is 300 or greater
        digitalWrite(ledPin, HIGH);       // turn the ledPin on
        Serial.print("LedOn, Knob=");
        Serial.println(knobValue);

      } // end of knobValue if/else

    } else {
      // button is not pressed off
      digitalWrite(ledPin, LOW);          // turn the ledPin off

    } // end of buttonState if/else

  } // end of toggleBtnState logic

}
