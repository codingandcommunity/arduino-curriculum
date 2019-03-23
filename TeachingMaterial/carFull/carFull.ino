// Original code from http://www.duino-robotics.com/james.html
// with modification by Dimitris Tsartsanis

#include <NewPing.h>

#define USTrigger 4
#define USEcho 2
#define MaxDistance 100

NewPing sonar(USTrigger, USEcho, MaxDistance);

int movemotorA = 12;
int brakeA = 9;
int speedmotorA = 3;
int movemotorB = 13;
int brakeB = 8;
int speedmotorB = 11;
int led = 10;
unsigned int duration;
unsigned int distance;
unsigned int FrontDistance;
unsigned int LeftDistance;
unsigned int RightDistance;
unsigned int Time;
unsigned int CollisionCounter;

void setup()                                            
{
  Serial.begin(9600);                              
  pinMode(movemotorA, OUTPUT);
  pinMode(movemotorB, OUTPUT);
  pinMode(brakeA, OUTPUT);
  pinMode(brakeB, OUTPUT);
  pinMode(led, OUTPUT);
  } 

void loop()          
{
  scan();              
  FrontDistance = distance;    
  Serial.println("Front distance = ");
  Serial.print(distance);
  if(FrontDistance > 20 || FrontDistance == 0) 
  {
   moveForward();                                     
  } 
  else                                               
  {
    CollisionCounter = CollisionCounter + 1;
    moveStop();          
    navigate();
  }
}

void moveForward()                 
{
  Serial.println("");
  Serial.println("Moving forward");
  digitalWrite(movemotorA, HIGH);
  digitalWrite(brakeA, LOW);
  analogWrite(speedmotorA, 255);
  digitalWrite(movemotorB, HIGH);
  digitalWrite(brakeB, LOW);
  analogWrite(speedmotorB, 255);
  digitalWrite(led, LOW);
  }

void moveBackward() 
{
  Serial.println("");
  Serial.println("Moving backward");
  digitalWrite(movemotorA, LOW);
  digitalWrite(brakeA, LOW);
  analogWrite(speedmotorA, 255);
  digitalWrite(movemotorB, LOW);
  digitalWrite(brakeB, LOW);
  analogWrite(speedmotorB, 255);
  digitalWrite(led, HIGH);
  }

void moveLeft()          
{
  Serial.println("");
  Serial.println("Moving left");
  digitalWrite(movemotorA, LOW);
  digitalWrite(brakeA, LOW);
  analogWrite(speedmotorA, 255);
  digitalWrite(led, LOW);
  
}

void moveRight()        
{
  Serial.println("");
  Serial.println("Moving right");
  digitalWrite(movemotorB, LOW);
  digitalWrite(brakeB, LOW);
  analogWrite(speedmotorB, 255);
  digitalWrite(led, LOW);
}

void moveStop()          
{
  Serial.println("");
  Serial.println("Stopping");
  digitalWrite(brakeA, HIGH);  
  digitalWrite(brakeB, HIGH);
  }
void scan()                  
{
  Serial.println("");
  Serial.println("Scanning");
  Time = sonar.ping(); 
  distance = Time / US_ROUNDTRIP_CM;
  delay(300);
}
void navigate()
{
    Serial.println("There's an obstacle!");
    FrontDistance = distance;
    if(FrontDistance <  5)
    {
      moveBackward();
      moveStop();
      moveRight();   
    }
    
  else if(FrontDistance > 6)
  {
    moveBackward();
    moveStop();
    moveLeft();  
  }
}

