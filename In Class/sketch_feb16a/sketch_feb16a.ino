
int ledPin = 10;
int knobPin = A0;
int knobValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  knobValue = analogRead(knobPin);
  
  knobValue = map(knobValue, 0, 1023, 0, 255);
  Serial.println(knobValue);
  analogWrite(ledPin, knobValue);
}
