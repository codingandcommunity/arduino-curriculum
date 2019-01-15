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
int first = 2;
int second = 3;
int third = 4;
int fourth = 5;
int fifth = 6;
int sixth = 7;

// pin for the button switch
int button = 12;
// value to check state of button switch
int pressed = 0;

void setup() {
  // set all LED pins to OUTPUT
  pinMode(first, OUTPUT);
  pinMode(second, OUTPUT);
  pinMode(third, OUTPUT);
  pinMode(fourth, OUTPUT);
  pinMode(fifth, OUTPUT);
  pinMode(sixth, OUTPUT);
  
  // set buttin pin to INPUT
  pinMode(button, INPUT);
  
  // initialize random seed by noise from analog pin 0 (should be unconnected)
  randomSeed(analogRead(0));

  // if we're debugging, connect to serial 
  #ifdef DEBUG
    Serial.begin(9600);
  #endif

}



void showNumber(int number) {
  digitalWrite(first, HIGH);
  if (number >= 2) {
    digitalWrite(second, HIGH);
  }
  if (number >= 3) {
    digitalWrite(third, HIGH);    
  }
  if (number >= 4) {
    digitalWrite(fourth, HIGH);    
  }
  if (number >= 5) {
    digitalWrite(fifth, HIGH);    
  }
  if (number == 6) {
    digitalWrite(sixth, HIGH);    
  }
}

void loop() {
  // if button is pressed - throw the dice
  pressed = digitalRead(button);

  if (pressed == HIGH) {
    // remove previous number to LOW
    digitalWrite(first, LOW);
    digitalWrite(second, LOW);
    digitalWrite(third, LOW);
    digitalWrite(fourth, LOW);
    digitalWrite(fifth, LOW);
    digitalWrite(sixth, LOW);
    
    // get a random number in the range [1,6]
    int thrownNumber = random(1,7);
    
    //write IF statements to light up the lights
    digitalWrite(first, HIGH);
    if (number >= 2) {
      digitalWrite(second, HIGH);
    }
    if (number >= 3) {
      digitalWrite(third, HIGH);    
    }
    if (number >= 4) {
      digitalWrite(fourth, HIGH);    
    }
    if (number >= 5) {
      digitalWrite(fifth, HIGH);    
    }
    if (number == 6) {
      digitalWrite(sixth, HIGH);    
    }
      
  } 

}