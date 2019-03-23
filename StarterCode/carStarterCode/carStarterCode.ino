// Original code from http://www.duino-robotics.com/james.html
// with modification by Dimitris Tsartsanis
// Source: https://www.instructables.com/id/Actobitty-2-wheel-object-avoidance-robot/

// TODO: Download the NewPing Library
// Download the zip file from here: https://playground.arduino.cc/Code/NewPing/
// Put the folder in the Arduino/libraries folder
// Go to Sketch -> Import Library -> NewPing
// Restart Arduino
#include <NewPing.h>

// pins for sensor
#define TriggerPin 4
#define EchoPin 2
#define MaxDistance 100

NewPing sonar(TriggerPin, EchoPin, MaxDistance);

// pins for motors, brakes, and led

// A motors & brake are on the left side of the car
int movemotorA; 
int brakeA;
int speedmotorA;

// B motors & brake are on the right side of the car
int movemotorB;
int brakeB;
int speedmotorB;

int led;

// unsigned int means that the variable can store
// 0 and positive numbers only
unsigned int speed = 255;
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
                               
  // TODO: set pins to INPUT or OUTPUT  
} 

void loop()          
{
  scan();              
  FrontDistance = distance;    
  Serial.println("Front distance = ");
  Serial.print(distance);

  // TODO: add code:
  // if an object was NOT detected, to move forward
  // otherwise, increment the collision counter, stop and move away
}

void moveForward()                 
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing
  
  // TODO: add code to move forward
  
  // TODO: turn the LED off
}

void moveBackward() 
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing
  
  // TODO: add code to move backwards

  // TODO: turn the LED on
}

void moveLeft()          
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing
  
  // TODO: add code to move left
  
}

void moveRight()        
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing
  
  // TODO: add code to move right
}

void moveStop()          
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing

  // TODO: add code to stop the robot
}

void scan()                  
{
  Serial.println("");
  // TODO: print something to tell the user what the car is doing

  // TODO: add code to get the distance the robot is from the car
  // 1. Get the "echo time", look at the methods here: https://playground.arduino.cc/Code/NewPing/
  
  // This converts the echo time to distance in centimeters
  distance = Time / US_ROUNDTRIP_CM;
  delay(300);
}

void navigate()
{
  // TODO: print something to tell the user what the car is doing
  FrontDistance = distance;

  // TODO: add code to move away from the detected object
  // One way you could do this would be:
  // if the robot is very close to the object, the robot backs up,
  // the light turns on, and the robot moves right
  // otherwise, the robot backs up, the light turns on, and the 
  // robot moves left
}

