void btControl(){

  if (Serial.available() > 0) { 
   
    /* Reset the iterator and clear the buffer */
    i = 0;
    memset(dataBuffer, 0, sizeof(dataBuffer));  
    
    /* Wait for let the buffer fills up. Depends on the length of 
       the data, 1 ms for each character more or less */
    delay(bufferSize); 

    /* Number of characters availables in the Bluetooth Serial */
    numChar = Serial.available();   
    
    /* Limit the number of characters that will be read from the
       Serial to avoid reading more than the size of the buffer */
    if (numChar > bufferSize) {
          numChar = bufferSize;
    }

    /* Read the Bluetooth Serial and store it in the buffer*/
    while (numChar--) {
        dataBuffer[i++] = Serial.read();

        /* As data trickles in from your serial port you are 
         grabbing as much as you can, but then when it runs out 
         (as it will after a few bytes because the processor is 
         much faster than a 9600 baud device) you exit loop, which
         then restarts, and resets i to zero, and someChar to an 
         empty array.So please be sure to keep this delay */
        delay(3);
    } 

    /* Manage the data */   
    checkData(dataBuffer);
  }
}



void checkData(char* data){
  if(direction != 1)
    direction = 0;

  switch(data[0]) {
    case 'I':
      currentState = SENSOR_CONTROL_STATE;
      break;
    case 'M':
      currentState = MANUAL_CONTROL_STATE;
      direction = 0;
      break;
    case'S':
      /* Stop button pressed */
      //stopWheels();
      direction = 0;
      break;
    
    case 'U':
      /* Up button pressed */
      //goForwards();
      direction = 1;
      break;
    
    case 'D':
      /* Down button pressed */
      //goBackwards();
      direction = 3;
      break;
      
    case 'L':
      /* Left button pressed */ 
      //goLeft();
      direction = 4;
      break;
      
    case 'R':
      /* Right button pressed */ 
      //goRight();
      direction = 2;
      break;
  
  }

  /* Empty the Serial */   
  Serial.flush();

}
