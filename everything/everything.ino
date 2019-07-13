int speaker_pin = 13;
int light_pin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker_pin, OUTPUT);
  pinMode(light_pin, OUTPUT);
}

void Buzz(int pin) {
  tone(speaker_pin, 300);
  delay(1000);
  noTone(speaker_pin);
  delay(1000);
}

void Blink(int pin) {
  digitalWrite(light_pin, HIGH);
  delay(1000);
  digitalWrite(light_pin, LOW);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Buzz(speaker_pin);
  Blink(light_pin);

  // Button -- controls everything?
  // Motor and fan function
  // Sensor function
  // Display a number
}


