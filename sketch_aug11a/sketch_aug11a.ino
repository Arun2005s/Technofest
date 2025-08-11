#include <Servo.h>

Servo regulator;
const int gasPin = A0;
const int buzzerPin = 8;
int threshold = 250;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
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
    regulator.write(90);
    delay(2000);
    digitalWrite(buzzerPin, LOW);
  } else {
    regulator.write(0);
    digitalWrite(buzzerPin, LOW);
  }

  delay(500);
}
