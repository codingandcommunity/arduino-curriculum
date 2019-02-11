/*
   Arduino based Piano and Record and play option
   Code by: B. Aswinth Raj
   Website: www.circuitdigest.com
   Dated: 22-05-2017
*/

#include <LiquidCrystal.h>

int notes[] = {262, 294, 330, 349, 392, 440, 494, 523}; // Set frequency for C4, D4, E4, F4, G4, A4, B4, C5

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char button = 0;
int analogVal;
char REC = 0;

int recorded_button[200];
int pev_button;

int recorded_time [200];
char time_index;

char button_index = 0;

unsigned long start_time;
int note_time;

void setup() {

  Serial.begin(9600);
  pinMode (6, INPUT);

  lcd.begin(16, 2); //We are using a 16*2 LCD display
  lcd.print("Arduino Piano"); //Display a intro message
  lcd.setCursor(0, 1);   // set the cursor to column 0, line 1
  lcd.print("-CircuitDigest"); //Display a intro message

  delay(2000); //Wait for display to show info
  lcd.clear(); //Then clean it

}

 

void loop() 
{

  while (digitalRead(6) == 0) //If the toggle switch is set in recording mode
  {
    lcd.setCursor(0, 0); lcd.print("Recording..");
    lcd.setCursor(0, 1);

    Detect_button();
    Play_tone();
  }

 
  while (digitalRead(6) == 1) //If the toggle switch is set in Playing mode
  {
  lcd.clear();
  lcd.setCursor(0, 0);  lcd.print("Now Playing..");

  for (int i = 0; i < sizeof(recorded_button) / 2; i++)
  {
    delay((recorded_time[i]) * 10); //Wait for before paying next tune

    if (recorded_button[i] == 0)
      noTone(7); //user dint touch any button
    else
      tone(7, notes[(recorded_button[i] - 1)]); //play the sound corresponding to the button touched by the user
  }
  }
}

 

void Detect_button()
{
  analogVal = analogRead(A0); //read the analog voltag on pin A0

  pev_button = button; //remember the previous button pressed by the user

  if (analogVal < 550)
    button = 8;

  if (analogVal < 500)
    button = 7;

  if (analogVal < 450)
    button = 6;

  if (analogVal < 400)
    button = 5;

  if (analogVal < 300)
    button = 4;

  if (analogVal < 250)
    button = 3;

  if (analogVal < 150)
    button = 2;

  if (analogVal < 100)
    button = 1;

  if (analogVal > 1000)
    button = 0;

    
/****Rcord the pressed buttons in a array***/
  if (button != pev_button && pev_button != 0)
  {
    recorded_button[button_index] = pev_button; 
    button_index++;
    recorded_button[button_index] = 0;
    button_index++;
  }
/**End of Recording program**/
}

void Play_tone()
{

 /****Rcord the time delay between each button press in a array***/
  if (button != pev_button)
  {
    lcd.clear(); //Then clean it
    note_time = (millis() - start_time) / 10;

    recorded_time[time_index] = note_time;
    time_index++;

    start_time = millis();
  }
  /**End of Recording program**/

  if (button == 0)
  {
    noTone(7);
    lcd.print("0 -> Pause..");
  }

  if (button == 1)
  {
    tone(7, notes[0]);
    lcd.print("1 -> NOTE_C4");
  }

  if (button == 2)
  {
    tone(7, notes[1]);
    lcd.print("2 -> NOTE_D4");
  }

  if (button == 3)
  {
    tone(7, notes[2]);
    lcd.print("3 -> NOTE_E4");
  }

  if (button == 4)
  {
    tone(7, notes[3]);
    lcd.print("4 -> NOTE_F4");
  }

  if (button == 5)
  {
    tone(7, notes[4]);
    lcd.print("5 -> NOTE_G4");
  }

  if (button == 6)
  {
    tone(7, notes[5]);
    lcd.print("6 -> NOTE_A4");
  }

  if (button == 7)
  {
    tone(7, notes[6]);
    lcd.print("7 -> NOTE_B4");
  }

  if (button == 8)
  {
    tone(7, notes[7]);
    lcd.print("8 -> NOTE_C5");
  }
}
