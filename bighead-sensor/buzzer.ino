void beep (int pin, float noteFrequency, long noteDuration)
{    
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)   
          {   
              digitalWrite(pin,HIGH); 
              delayMicroseconds(microsecondsPerWave); 
              digitalWrite(pin,LOW); 
              delayMicroseconds(microsecondsPerWave); 
          } 
}     
     
void scale() 
{    
          beep(BuzzerPin, note_C7,500); //C: play the note C for 500ms 
          beep(BuzzerPin, note_D7,500); //D 
          beep(BuzzerPin, note_E7,500); //E 
          beep(BuzzerPin, note_F7,500); //F 
          beep(BuzzerPin, note_G7,500); //G 
          beep(BuzzerPin, note_A7,500); //A 
          beep(BuzzerPin, note_B7,500); //B 
          beep(BuzzerPin, note_C8,500); //C 
}  

void r2D2(){
          beep(BuzzerPin, note_A7,100); //A 
          beep(BuzzerPin, note_G7,100); //G 
          beep(BuzzerPin, note_E7,100); //E 
          beep(BuzzerPin, note_C7,100); //C
          beep(BuzzerPin, note_D7,100); //D 
          beep(BuzzerPin, note_B7,100); //B 
          beep(BuzzerPin, note_F7,100); //F 
          beep(BuzzerPin, note_C8,100); //C 
          beep(BuzzerPin, note_A7,100); //A 
          beep(BuzzerPin, note_G7,100); //G 
          beep(BuzzerPin, note_E7,100); //E 
          beep(BuzzerPin, note_C7,100); //C
          beep(BuzzerPin, note_D7,100); //D 
          beep(BuzzerPin, note_B7,100); //B 
          beep(BuzzerPin, note_F7,100); //F 
          beep(BuzzerPin, note_C8,100); //C 
}

void closeEncounters() {
          beep(BuzzerPin, note_Bb5,300); //B b
          delay(50);
          beep(BuzzerPin, note_C6,300); //C
          delay(50);
          beep(BuzzerPin, note_Ab5,300); //A b
          delay(50);
          beep(BuzzerPin, note_Ab4,300); //A b
          delay(50);
          beep(BuzzerPin, note_Eb5,500); //E b   
          delay(500);     
          
          beep(BuzzerPin, note_Bb4,300); //B b
          delay(100);
          beep(BuzzerPin, note_C5,300); //C
          delay(100);
          beep(BuzzerPin, note_Ab4,300); //A b
          delay(100);
          beep(BuzzerPin, note_Ab3,300); //A b
          delay(100);
          beep(BuzzerPin, note_Eb4,500); //E b   
          delay(500);  
          
          beep(BuzzerPin, note_Bb3,300); //B b
          delay(200);
          beep(BuzzerPin, note_C4,300); //C
          delay(200);
          beep(BuzzerPin, note_Ab3,300); //A b
          delay(500);
          beep(BuzzerPin, note_Ab2,300); //A b
          delay(550);
          beep(BuzzerPin, note_Eb3,500); //E b      
}

void ariel() {

          beep(BuzzerPin, note_C6,300); //C
          delay(50);
          beep(BuzzerPin, note_D6,300); //D
          delay(50);
          beep(BuzzerPin, note_Eb6,600); //D#
          delay(250);
          
          beep(BuzzerPin, note_D6,300); //D
          delay(50);
          beep(BuzzerPin, note_Eb6,300); //D#
          delay(50);
          beep(BuzzerPin, note_F6,600); //F
          delay(250);
          
          beep(BuzzerPin, note_C6,300); //C
          delay(50);
          beep(BuzzerPin, note_D6,300); //D
          delay(50);
          beep(BuzzerPin, note_Eb6,500); //D#
          delay(50);          
          beep(BuzzerPin, note_D6,300); //D
          delay(50);
          beep(BuzzerPin, note_Eb6,300); //D#
          delay(50);             
          beep(BuzzerPin, note_D6,300); //D
          delay(50);
          beep(BuzzerPin, note_Eb6,300); //D#
          delay(50);
          beep(BuzzerPin, note_F6,600); //F
          delay(50); 

}
 

void laugh2() {
          beep(BuzzerPin, note_C6,200); //C
          beep(BuzzerPin, note_E6,200); //E  
          beep(BuzzerPin, note_G6,200); //G 
          beep(BuzzerPin, note_C7,200); //C 
          beep(BuzzerPin, note_C6,200); //C
          delay(50);
          beep(BuzzerPin, note_C6,200); //C
          beep(BuzzerPin, note_E6,200); //E  
          beep(BuzzerPin, note_G6,200); //G 
          beep(BuzzerPin, note_C7,200); //C 
          beep(BuzzerPin, note_C6,200); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          delay(50);
          beep(BuzzerPin, note_C6,50); //C
          

          
}
  
void squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    beep(BuzzerPin,i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    beep(BuzzerPin,i,20);
  }
}

void waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    beep(BuzzerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(BuzzerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(BuzzerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(BuzzerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(BuzzerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(BuzzerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(BuzzerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(BuzzerPin,i,10);
  }
}

void catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    beep(BuzzerPin,i,10);
  }
 delay(300);
 
  for (int i=1000; i<3000; i=i*1.03) {
    beep(BuzzerPin,i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    beep(BuzzerPin,i,10);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    beep(BuzzerPin,i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    beep(BuzzerPin,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(BuzzerPin,i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(BuzzerPin,i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(BuzzerPin,i,10);
  }
  delay(50);
}