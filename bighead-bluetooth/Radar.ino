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

/**
* Trigger the outward ping pulse(s)
*/
void ping(){ 
 // Serial.println("ping out");  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10); // I think I can cope with blocking for a whole 10us here...
  digitalWrite(TRIGGER_PIN, LOW);
  
  // start listening out for the echo pulse on interrupt 0
  PulseInZero::begin();
}
 
 
/**
* Pulse complete callback hanlder for PulseInZero 
* @param duration - pulse length in microseconds
*/
void pingPulseComplete(unsigned long duration) { 
  millimetres = MicrosecondsToMillimetres2 * duration;
  direction = 1;
//  Serial.println(millimetres);
  if(millimetres < 200.00){
    direction = random(2, 5);
  }
  if(millimetres > 4000){
    millimetres = 4000;
  }
}