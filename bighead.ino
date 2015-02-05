#include <Servo.h>
#include <PulseInOne.h>

/** 
* On utilise des #define plutôt que des variables sur les constantes
* cela prend moins de place en mémoire vive !! (car remplacées lors de la complilation)
*/

#define BuzzerPin 13

#define red 12
#define yellow 11
#define green 10

#define EnableServo 14  // activation des servos (la pin 14 est en faite la pin A0)
Servo Lleg;  // create servo object to control a servo 
Servo Rleg;
Servo Lfoot;
Servo Rfoot;

int Speed = 70;

int RFcenter = 90;    // variable to store the center servo position 
int LLcenter = 90;
int RLcenter = 87;
int LFcenter = 90;
int tAngle = 10; //tilt angle
int uAngle = 15; //turn angle
int sAngle = 30; //swing angle

long cm;                // variable pour stocker la distance de l'objet en cm

// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE 300
// Arduino pin tied to trigger pin on the ultrasonic sensor.
#define TRIGGER_PIN  12
// Arduino pin tied to echo pin on the ultrasonic sensor.
#define ECHO_PIN     2

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int Obstacle = 0;

const float SpeedOfSound = 343.2; // ~speed of sound (m/s) in air, at 20°C         
const float MicrosecondsPerMillimetre = 1000.0 / SpeedOfSound; // microseconds per millimetre - sound travels 1 mm in ~2.9us
const float MicrosecondsToMillimetres = (1.0 / MicrosecondsPerMillimetre);
const float MicrosecondsToMillimetres2 = MicrosecondsToMillimetres / 2.0; // beam travels the distance twice... so halve the time.
unsigned long lastTime  = 0; 
int pingTimer     = 0;
int pingDelay     = 500; // milliseconds between ping pulses 
float millimetres     = 0.0;



/**
 * Arduino setup function
 * @return void
 */
void setup(){
  Lleg.attach(5);  // attaches the servo on pin x to the servo object 
  Rleg.attach(4);  // attaches the servo on pin x to the servo object 
  Lfoot.attach(7);  // attaches the servo on pin x to the servo object 
  Rfoot.attach(6);  // attaches the servo on pin x to the servo object 
  CenterServos(); //center the servos
  
  pinMode(green, OUTPUT);	digitalWrite(green, LOW);
  pinMode(yellow, OUTPUT);	digitalWrite(yellow, LOW);
  pinMode(red, OUTPUT);		digitalWrite(red, LOW);
  
  pinMode(BuzzerPin, OUTPUT);	digitalWrite(BuzzerPin, LOW);
  pinMode(BuzzerPin-1, OUTPUT);	digitalWrite(BuzzerPin-1, LOW); // branchement buzzer (identique a GND)
  //Buzzer.PlayMelody();
  
  Serial.begin(19200);
  Serial.println("Ready");


  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);   
  PulseInOne::setup(pingPulseComplete);

  BuzzerBeep();
  for(int i=0;i<5;++i){
    delay(1000);
  }
  BuzzerBeep();
}
void updatePingTimer(){
  unsigned long time = millis();
  unsigned long dt   = time - lastTime;
  lastTime       = time;
  
  pingTimer += dt;
  if(pingTimer > pingDelay){  
    pingTimer = 0;
    ping();
  }
}
void loop() { 
  Walk();
  /*switch (Obstacle){
    case 0: //no object
       Forward(10,90); //one step Forward
       BuzzerBeep();
       break;
     case 1: //object on Left
       TurnRight(2,60);
       BuzzerBeep();
       break;
     case 2: //object on Right
       TurnLeft(2,60);
       BuzzerBeep();
       break;
     case 3: //obect in Front (both Left and Right detect the object)
       TurnLeft(4,60); //turn around
       BuzzerBeep();
       break;
   }*/  
}


/**
 * Center servos
 */
void CenterServos() { 
    Lleg.write(LLcenter);
    // tell servo to go to position in variable 'center' 
    Rleg.write(RLcenter);
    // tell servo to go to position in variable 'center' 
    Lfoot.write(LFcenter);
    // tell servo to go to position in variable 'center' 
    Rfoot.write(RFcenter);
    // tell servo to go to position in variable 'center' 
    delay(100);
    // waits 100ms for the servos to reach the position 
}

void BuzzerBeep() {
	int tpstone=230;
	for (int i=0; i <= 999; i++) {
		digitalWrite(BuzzerPin, HIGH); delayMicroseconds(tpstone);
		digitalWrite(BuzzerPin, LOW); delayMicroseconds(tpstone);
	}
}

//La fonction ci-dessous fait clignoter la LED correspondant à la distance.
//Le clignotement est de plus en plus rapide à mesure que l'objet se rapproche.
void blink(int pause, int ledPin) {
  pause = pause * 10;
  digitalWrite(ledPin, HIGH);
  delay(pause);
  digitalWrite(ledPin, LOW);
  delay(10);
}