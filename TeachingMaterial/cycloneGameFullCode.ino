//arrays
int ledPins[8] = {3,4,5,6,7,8,9,10};
//speed
double tempo = 300;
int score = 0;
boolean midLed = false;
// pin for the button switch
int button = 12;
//declare functions
void interrupt();
void endFunction();

void setup(){
 //set ledPins to OUTPUT
 for( int i = 0 ; i < 8 ; i++ ){
   pinMode( ledPins[i] , OUTPUT );
 }
 //set button to INPUT
 pinMode( button , INPUT );
 //attach Interrupt
 attachInterrupt( 0 , interrupt , FALLING );
}

void loop(){
 //turn each LED on and then off
 for( int i = 0 ; i < 8 ; i++ ){
  //checks if middle LED
   if (i == 3) {
     digitalWrite( ledPins[i] , HIGH);
     midLed = true;
     delay( tempo );
     digitalWrite( ledPins[i] , LOW);
     midLed = false;
   } else {
      digitalWrite( ledPins[i] , HIGH );
      delay( tempo );
      digitalWrite( ledPins[i] , LOW );
   }
 }
}

void endFunction(){
 Serial.begin(9600);
 Serial.print( "Your score: " );
 Serial.println( score );
 digitalWrite( ledPins[3] , HIGH );
 while(1){
   //game over
 }
}

void interrupt(){
 delayMicroseconds(20000);
 //IF button not Pressed
 if( digitalRead( button ) == HIGH ){
   return;
 } //else increase speed and change score
 tempo = tempo * 9 / 10;
 if( midLed ){
   score++;
 }
 else{
   endFunction();
 }
}
