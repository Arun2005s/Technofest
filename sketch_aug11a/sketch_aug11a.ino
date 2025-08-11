const int gasSensorPin = A0;  // Analog pin connected to MQ-5 AOUT
const int buzzerPin = 3;      // Digital pin connected to buzzer
const int threshold = 300;    // Adjust this based on your testing

void setup() {
  Serial.begin(9600);
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is off at start
}

void loop() {
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    digitalWrite(buzzerPin, HIGH); // Buzzer ON
    Serial.println("Gas Detected!");
  } else {
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF
  }

  delay(500); // Adjust as needed
}
