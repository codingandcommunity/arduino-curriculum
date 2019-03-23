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
int button = 2;

// pin for buzzer
int buzzer = 6;
// value to check state of button switch
int pressed = HIGH;

int score = 0;

int currentLight = 0;
void setup() {
  // set all LED pins to OUTPUT
  //using arrays
//  Serial.begin(9600);
  for(int i = 0; i<6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // set button pin to INPUT
  pinMode(button, INPUT);
  digitalWrite(button,HIGH);
  // set buzzer pin to OUTPUT
  pinMode(buzzer, OUTPUT);
//  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, interrupt, FALLING);
  Serial.begin(9600);
  
}

void Buzzer(int frequency) {
  tone(buzzer, frequency);
  delay(1000);
  noTone(buzzer);
}

void loop() {
  // if button is pressed - throw the dice

  int delayTime = 300; // decrease to make game harder
  pressed = digitalRead(button);
  digitalWrite(ledPins[5], HIGH);
  delay(100);
  digitalWrite(ledPins[5], LOW);
  delay(100);
  digitalWrite(ledPins[5], HIGH);
  delay(100);
  digitalWrite(ledPins[5], LOW);
  delay(100);
  digitalWrite(ledPins[5], HIGH);
  delay(100);
  digitalWrite(ledPins[5], LOW);
  delay(100);
  
  
  while(true) {
    digitalWrite(ledPins[currentLight], HIGH);


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

//
void interrupt(){
// delayMicroseconds(20000);
 pressed = digitalRead(button);
  Serial.println("-----------");
// //IF button not Pressed exit function

if (pressed == LOW && currentLight == 5) {
      score++;
      Serial.print("You win!\nYour score is:");
     Serial.println(score);
      Buzzer(1000);
      delay(80);
     
    } 
    else if (pressed == LOW && currentLight != 5) {
      score--;
      Serial.print("You lose\nYour score is:");
      Serial.println(score);
      Buzzer(1500);
      delay(80);
    }

}
