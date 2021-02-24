/* Goal: count the number of times a button is pressed */

int buttonPin = 9;
int buttonState = 0;
int lastButtonState = 0;
int counter = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  // check if the buttonState has changed
  if (buttonState != lastButtonState) {
    // only if it has been pressed (not released)
    if (buttonState == 1) {
      // increment the counter
      counter = counter + 1;
      Serial.println(counter);
    }
    // reset lastButtonState to save the current state
    lastButtonState = buttonState;
  }
  
}
