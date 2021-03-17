int knobPin = A0;
int knobValue = 0;

int sensorPin = A1;
int sensorValue = 0;

int buttonPin = 2;
int buttonValue = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  knobValue = analogRead(knobPin);
  Serial.print(knobValue);
  Serial.print("\t");

  sensorValue = analogRead(sensorPin);
  Serial.print(sensorValue);
  Serial.print("\t");

  buttonValue = digitalRead(buttonPin);
  Serial.print(buttonValue);
  Serial.print("\t");

  Serial.println();
  // end goal: print everything on a single line separated by \t

}
