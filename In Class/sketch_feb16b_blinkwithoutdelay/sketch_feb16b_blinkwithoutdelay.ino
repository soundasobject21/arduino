int ledPin = 10;
int ledPin2 = 11;

int knobPin = A0;
int knobPin2 = A1;

int ledState = LOW;
int ledState2 = LOW;

int knobValue = 0;
int knobValue2 = 0;

// store the last time the task was completed
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;

// task interval
long interval = 1000;
long interval2 = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // check the elapsed time since the program started
  unsigned long currentMillis = millis();

  knobValue = analogRead(knobPin);
  interval = long(knobValue);

  knobValue2 = analogRead(knobPin2);
  Serial.println(knobValue2);
  knobValue2 = map(knobValue2, 400, 900, 0, 1000);
  interval2 = long(knobValue2);

  // check the time for task 1
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  } // task 1 complete

  // check the time for task 2
  if (currentMillis - previousMillis2 >= interval2) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState2);
  } // task 2 complete

}
