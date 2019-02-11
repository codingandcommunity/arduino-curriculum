/* 
 Arduino Dice :)

 This example shows how to simulate throwing a dice with 6 LEDs.

 The circuit:
 * 6 LEDs attached to consecutive digital pins (with 220 Ohm resistors)
 * Button switch connected to digital pin (see circuit on https://www.arduino.cc/en/Tutorial/Button)

 Created 5 Jan 2017
 By Esther van der Stappen
 
 This example code is in the public domain.

 */

// set to 1 if we're debugging
#define DEBUG 0

// 6 consecutive digital pins for the LEDs
int ledPins[] = {13, 12, 11, 10, 9, 8};

// pin for the button switch
int button = 7;

// pin for buzzer
int buzzer = 6;
// value to check state of button switch
int pressed = 0;

int score = 0;

void setup() {
  // set all LED pins to OUTPUT
  //using arrays
  for(int i = 0; i<6; i++) {
    pinMode(i, OUTPUT);
  }
  
  // set button pin to INPUT
  pinMode(button, INPUT);
  // set buzzer pin to OUTPUT
  pinMode(buzzer, OUTPUT);
  
}

void buzzer(int frequency) {
  tone(buzzer, frequency);
  delay(1000);
  noTone(buzzer);
}

void loop() {
  // if button is pressed - throw the dice
  pressed = digitalRead(button);
  int currentLight = 0;
  int delayTime = 1000; // decrease to make game harder
  
  while(true) {
    digitalWrite(ledPins[currentLight], HIGH);

    if (pressed == LOW && currentLight == 5) {
      Serial.print("You win!\nYour score is:", score);
      buzzer(1000);
      score++;
    } 
    else if (pressed == LOW && currentLight != 5) {
      Serial.print("You lose\nYour score is:", score);
      buzzer(1500);
      score--;
    }

    delay(delayTime);
    digitalWrite(ledPins[currentLight], LOW);
    delay(delayTime);

    if (currentLight == 5){
      currentLight = 0;
    } else {
      currentLight++;
    }
  }
  
}