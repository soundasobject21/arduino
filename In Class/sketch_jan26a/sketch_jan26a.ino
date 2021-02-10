
// declare and initialize variables outside of functions

int ledPin = 13; // digital pin

int knobPin = A0; // analog pin
int knobValue = 0; // where to store knob value

int buttonPin = 7; // my button
int buttonState = 0; // where to store my button value

void setup() {
  // setup function
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

  // start serial communications
  Serial.begin(9600);
}

void loop() {
  // looping function
  // put your main code here, to run repeatedly

  buttonState = digitalRead(buttonPin);
  knobValue = analogRead(knobPin);
  Serial.println((String) "Button: " + buttonState + "; Knob: " + knobValue);

  if (buttonState == 1) {
    // turn on the LED
    digitalWrite(ledPin, HIGH);
  } else {
    // if not true, blink the LED
    digitalWrite(ledPin, HIGH);
    delay(knobValue);
    digitalWrite(ledPin, LOW);
    delay(knobValue);
  }

}
