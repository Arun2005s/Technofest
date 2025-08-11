#include <Servo.h>

Servo regulator;
const int gasPin = A0;
const int buzzerPin = 8;
const int fanPin = 7;
int threshold = 300;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  digitalWrite(fanPin, LOW);
  
  regulator.attach(9);
  regulator.write(0);
}

void loop() {
  int gasValue = analogRead(gasPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    Serial.println("🚨 Gas Leak Detected!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(fanPin, HIGH);
    regulator.write(90);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
  } else {
    regulator.write(0);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(fanPin, LOW);
  }

  delay(500);
}
