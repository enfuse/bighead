void Walk(){
  Obstacle = 0;
  updatePingTimer();
  if(Obstacle==0)
    TiltRightUp(tAngle, Speed);
  while (Obstacle==0){
    stepForward(Speed);
    updatePingTimer();
  }
  TiltRightDown(tAngle, Speed);
  switch (Obstacle){
     case 1: //object on Left
        ohhh();
       TurnRight(2,60);
       break;
     case 2: //object on Right
        ohhh();
       TurnLeft(2,60);
       break;
     case 3: //obect in Front (both Left and Right detect the object)
        ohhh();
       TurnLeft(4,60); //turn around
       break;
   }
}

void stepForward(byte Speed){
  SwingRight(sAngle, Speed);
  TiltRightDown(tAngle, Speed);
  TiltLeftUp(tAngle, Speed);
  SwingRcenter(sAngle, Speed);
  SwingLeft(sAngle, Speed);
  TiltLeftDown(tAngle, Speed);
  TiltRightUp(tAngle, Speed);
  SwingLcenter(sAngle, Speed);
}

void stepBackward(byte Speed){
  RightLegIn(sAngle, Speed);
  TiltRightDown(uAngle, Speed);
  TiltLeftUp(uAngle, Speed);
  RightLegIcenter(sAngle, Speed);
  LeftLegOut(sAngle, Speed);
  TiltLeftDown(uAngle, Speed);
  TiltRightUp(uAngle, Speed);
  LeftLegOcenter(sAngle, Speed);
}

void TurnLeft(byte Steps, byte Speed){
  Back(1, Speed);
  TiltLeftUp(uAngle, Speed);
  delay(20);
  for (byte j=0; j<Steps; ++j){
    LeftLegIn(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    delay(20);
    LeftLegIcenter(sAngle, Speed);
    RightLegOut(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    delay(20);
    RightLegOcenter(sAngle, Speed);
  }
  TiltLeftDown(uAngle, Speed);  Obstacle = 0;
}

void TurnRight(byte Stps, byte Speed){
  Back(1, Speed);
  TiltRightUp(uAngle, Speed);
  delay(20);
  for (byte f=0; f<=Stps; ++f){
    RightLegIn(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    delay(20);
    RightLegIcenter(sAngle, Speed);
    LeftLegOut(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    delay(20);
    LeftLegOcenter(sAngle, Speed);
  }
  TiltRightDown(uAngle, Speed);Obstacle = 0;
}

void Back(byte Steps, byte Speed){
  digitalWrite(EnableServo,HIGH);
  TiltRightUp(uAngle, Speed);
  delay(20);
  for (byte j=0; j<Steps; ++j){
    RightLegIn(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    delay(20);
    RightLegIcenter(sAngle, Speed);
    LeftLegOut(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    delay(20);
    LeftLegOcenter(sAngle, Speed);
  }
  TiltRightDown(uAngle, Speed);
  digitalWrite(EnableServo,LOW);Obstacle = 0;
}

void forward(byte Steps, byte Speed){
  TiltRightUp(tAngle, Speed);
  for (byte j=0; j<Steps; ++j){
    SwingRight(sAngle, Speed);
    TiltRightDown(tAngle, Speed);
    TiltLeftUp(tAngle, Speed);
    SwingRcenter(sAngle, Speed);
    SwingLeft(sAngle, Speed);
    TiltLeftDown(tAngle, Speed);
    TiltRightUp(tAngle, Speed);
    SwingLcenter(sAngle, Speed);
  }
  TiltRightDown(tAngle, Speed);
  digitalWrite(EnableServo,LOW);Obstacle = 0;
}
