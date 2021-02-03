
// declare and initialize variables outside of functions

int ledPin = 13; // digital pin

int knobPin = A0; // analog pin
int knobValue = 0; // where to store knob value

void setup() {
  // setup function
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  // start serial communications
  Serial.begin(9600);
}

void loop() {
  // looping function
  // put your main code here, to run repeatedly
  knobValue = analogRead(knobPin);
  Serial.println(knobValue);

  if (knobValue < 500) {
    // if true, do this
    digitalWrite(ledPin, HIGH);
  } else if (knobValue > 900) {
    digitalWrite(ledPin, LOW);
  } else {
    // if not true, do this
    digitalWrite(ledPin, HIGH);
    delay(knobValue);
    digitalWrite(ledPin, LOW);
    delay(knobValue);
  }

}
