#include "pitches.h"
#define ACTIVATED LOW


const int PIEZO = 11;
const int LED = 13;

int buttonSong = 8;
const int BUTTON_C = 6;
const int BUTTON_AS = 4;
const int BUTTON_A = 3;
const int BUTTON_G = 2;


void setup()
{
  Serial.begin(9600);
  //Initialize Buttons
}


// notes in the melody:
int melody[] = {
//use preset pitches to make a songe




};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  
//set duration of notes

};


void loop()
{
  //while Button is pressed, play set tone
  //do this for all buttons
  //else play no tone

}
