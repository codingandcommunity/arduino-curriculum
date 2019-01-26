//arrays
int ledPins[8] = {3,4,5,6,7,8,9,10};
//speed
double tempo = 300;
int score = 0;
boolean midLed = false;
// pin for the button switch
int button = 12;

void interrupt();
void endFunction();

void setup(){
 for( int i = 0 ; i < 8 ; i++ ){
   pinMode( ledPins[i] , OUTPUT );
 }
 pinMode( button , INPUT );
 attachInterrupt( 0 , interrupt , FALLING );
}

void loop(){
 for( int i = 0 ; i < 8 ; i++ ){
   if (i == 6) {
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
 if( digitalRead( button ) == HIGH ){
   return;
 }
 tempo = tempo * 9 / 10;
 if( midLed ){
   score++;
 }
 else{
   endFunction();
 }
}
