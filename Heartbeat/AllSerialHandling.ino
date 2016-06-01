/////////
/////////  All Serial Handling Code (originating from Pulse Sensor Amped 1.4)
/////////

void serialOutput(){   // Decide How To Output Serial. 
   //sendDataToSerial('S', Signal);     // goes to sendDataToSerial function    
}

//  Decides How To OutPut BPM and IBI Data
void serialOutputWhenBeatHappens(){    
 // sendDataToSerial('B',BPM);   // send heart rate with a 'B' prefix
  sendDataToSerial('Q',IBI);   // send time between beats with a 'Q' prefix   
}

//  Sends Data to Pulse Sensor Processing App, Native Mac App, or Third-party Serial Readers. 
void sendDataToSerial(char symbol, int data ){
  Serial.print(symbol);
  Serial.println(data);                
}
