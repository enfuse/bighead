/**
 * BiGHead Robot
 *
 * Lets make an easy to build robot so kids can learn how to build, program and play with it!!
 *
 */
#include <Servo.h>
#include "notas.h"
#include <PulseInOne.h>


/**
 * Bluetooth commands and config
 */

#define CMD_FORWARD 'U'
#define CMD_BACKWARD 'D'
#define CMD_TURNLEFT 'L'
#define CMD_TURNRIGHT 'R'
#define CMD_TURNAROUND 'C'
#define CMD_STOP 'S'

#define bufferSize 5
char dataBuffer[bufferSize]; 
int i = 0;
int numChar = 0;   

/**
 * Buzzzzzer
 */
#define BuzzerPin  9

/**
 * Servo config
 */
#define EnableServo 11 //Activación de servos

Servo Lleg;  // create servo object to control a servo 
Servo Rleg;
Servo Lfoot;
Servo Rfoot;

int Speed = 50; //Maybe regulable?

//Servo center positions
int RFcenter = 90;    
int LLcenter = 90;
int RLcenter = 87;
int LFcenter = 90;

//Movement angle
int tAngle = 18; //tilt angle [inclinación lateral]
int uAngle = 15; //turn angle [giro]
int sAngle = 30; //swing angle [cadera, longitud de paso]

/**
 * Ultrasound sensor config and variables
 */
#define MAX_DISTANCE 200
#define TRIGGER_PIN  12
#define ECHO_PIN     2
long cm;                

//Obstacle status
int Obstacle = 0;

// Some constants
const float SpeedOfSound = 343.2; // ~speed of sound (m/s) in air, at 20°C         
const float MicrosecondsPerMillimetre = 1000.0 / SpeedOfSound; // microseconds per millimetre - sound travels 1 mm in ~2.9us
const float MicrosecondsToMillimetres = (1.0 / MicrosecondsPerMillimetre);
const float MicrosecondsToMillimetres2 = MicrosecondsToMillimetres / 2.0; // beam travels the distance twice... so halve the time.
unsigned long lastTime = 0; 
int pingTimer = 0;
int pingDelay = 500; // milliseconds between ping pulses 
float millimetres = 0.0;



/**
 * Arduino setup function
 * @return void
 */
void setup(){
  //attach servos to pins
  Rleg.attach(4);
  Lleg.attach(5);
  Rfoot.attach(6);
  Lfoot.attach(7);
  
  CenterServos(); //center the servos

  randomSeed(analogRead(0)); //For now, bighead will turn randomly so we need this

  //pinMode(13, OUTPUT);  //Usually for debug only
   
  pinMode(BuzzerPin, OUTPUT);	digitalWrite(BuzzerPin, LOW);
  
  //Serial init, magic is fun
  Serial.begin(9600);
  //Serial.println("Ready");

  //Ultrasound init, PulseInOne library included
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);   
  PulseInOne::setup(pingPulseComplete);

  //BuzzerBeep(); //he!! Do we need this simple beep? I want music!!
  
  //for(int i=0;i<5;++i){
  //  delay(1000);
  //}
  squeak(); //Energized!!!
}


void loop() {
  Walk();
}


/**
 * Center servos
 */
void CenterServos() { 
    Lleg.write(LLcenter);
    Rleg.write(RLcenter);
    Lfoot.write(LFcenter); 
    Rfoot.write(RFcenter); 
    delay(100);
}
