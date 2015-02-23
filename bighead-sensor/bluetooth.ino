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

  switch(data[0]) {
    case'S':
      /* Stop button pressed */
      //stopWheels();
      break;
    
    case 'U':
      /* Up button pressed */
      //goForwards();
      forward(1,60);
      break;
    
    case 'D':
      /* Down button pressed */
      //goBackwards();
      break;
      
    case 'L':
      /* Left button pressed */ 
      //goLeft();
      break;
      
    case 'R':
      /* Right button pressed */ 
      //goRight();
      break;
  
  }

  /* Empty the Serial */   
  Serial.flush();

}
