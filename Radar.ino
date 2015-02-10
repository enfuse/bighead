
/**
* Trigger the outward ping pulse(s)
*/
void ping(){ 
 // Serial.println("ping out");  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // I think I can cope with blocking for a whole 10us here...
  digitalWrite(TRIGGER_PIN, LOW);
  
  // start listening out for the echo pulse on interrupt 0
  PulseInOne::begin();
}
 
 
/**
* Pulse complete callback hanlder for PulseInZero 
* @param duration - pulse length in microseconds
*/
void pingPulseComplete(unsigned long duration) { 
  millimetres = MicrosecondsToMillimetres2 * duration;
  if(millimetres < 200.00){
    Obstacle = random(1, 4);
  }
  if(millimetres > 4000){
    millimetres = 4000;
  } 
}