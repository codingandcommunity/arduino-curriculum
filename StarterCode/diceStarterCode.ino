/* 
 Arduino Dice :)

 This example shows how to simulate throwing a dice with 6 LEDs
 By Esther van der Stappen

 */

// 6 consecutive digital pins for the LEDs
int first;
int second;
int third ;
int fourth;
int fifth;
int sixth;

// pin for the button switch
int button;
// value to check state of button switch
int pressed;

void setup() {
  // set all LED pins to OUTPUT

  // set buttin pin to INPUT

  // initialize random seed by noise from analog pin 0 (should be unconnected)
  randomSeed(analogRead(0));
}

void loop() {
  // if button is pressed - throw the dice
  pressed;

  if (pressed == HIGH) {
    // remove previous number to LOW
    
    // get a random number in the range [1,6]
    
    //write IF statements to light up the lights
    digitalWrite(first, HIGH);    
  } 
}