/**************************************
 Lesson 6: Using Conditionals: Switch between modes
  
  Additional materials
  - 1 10K ohm resistors
  - 1 switch (https://www.adafruit.com/product/805)

**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int knobPin = A0;     // analog pin because range of numbers
int knobValue = 0;    // variable for reading the knob

int buttonPin = 7;    // digital pin because binary (on/off)
int buttonState = 0;  // variable for reading the switch

void setup() {
  // put your setup code here, which runs once
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);
  
  // set digital pins as inputs:
  pinMode(buttonPin, INPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  //buttonState = digitalRead(buttonPin); // check if switch is on
  Serial.print("Button: ");
  Serial.println(buttonState);

  if (digitalRead(buttonPin) == 1) {
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
    // button isn't pressed
    digitalWrite(ledPin, LOW);          // turn the ledPin off
    
  } // end of buttonState if/else

}
