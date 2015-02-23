void TurnLeft(byte Steps, byte Speed){
  TiltLeftUp(uAngle, Speed);
  for (byte j=0; j<Steps; ++j){
    LeftLegIn(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);  
    LeftLegIcenter(sAngle, Speed);
    RightLegOut(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);   
    RightLegOcenter(sAngle, Speed);  
  }
  TiltLeftDown(uAngle, Speed);
}

void TurnRight(byte Stps, byte Speed){
  TiltRightUp(uAngle, Speed);
  for (byte f=0; f<Stps; ++f){
    RightLegIn(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    RightLegIcenter(sAngle, Speed);
    LeftLegOut(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    LeftLegOcenter(sAngle, Speed);
  }
  TiltRightDown(uAngle, Speed);
}

void Backward(byte Steps, byte Speed){
  TiltRightUp(uAngle, Speed);
  for (byte j=0; j<Steps; ++j){
    RightLegIn(sAngle, Speed);
    TiltRightDown(uAngle, Speed);
    TiltLeftUp(uAngle, Speed);
    RightLegIcenter(sAngle, Speed);
    LeftLegOut(sAngle, Speed);
    TiltLeftDown(uAngle, Speed);
    TiltRightUp(uAngle, Speed);
    LeftLegOcenter(sAngle, Speed);
  }
  TiltRightDown(uAngle, Speed);
}

void Forward(byte Steps, byte Speed){
  TiltRightUp(tAngle, Speed);
  while(direction == 0){
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