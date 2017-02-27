void Fourier(){ 
 
 // Check if we have enough data for Fourier transform (lower than 31 means not enough) 
 // if not enough, add current reading to the array
 if (dataCount < 31){
    dataCount++;
    data[dataCount] = IBI;
  }
 // If enough data is gathered, continue with calculation
  else{        
  	for (int i = 0 ; i < FHT_N-1 ; i++) { // save 256 samples
  		data[i] = data[i+1];
  	}
			// add current reading to the list
   data[31]=IBI;
    
   for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      fht_input[i] = data[i]; // put real data into bins
    }
    
    noInterrupts();
    fht_window(); 	// window the data for better frequency response
    fht_reorder(); 	// reorder the data before doing the fht
    fht_run(); 		// process the data in the fht
    fht_mag_log(); 	// get the output of the fht
    interrupts();
      
    for (int a = 2; a < 5; a++){
      LF += fht_log_out[a];
    }
    
    for (int a = 6; a < 12; a++){
      HF += fht_log_out[a];
    }
    LF=LF/3;
    HF=HF/6;
    LFHF=LF/HF;
    //Serial.println(LF);
    //Serial.println(HF);
    //Serial.println(LFHF);

    vibeTimeSet = 500*((LFHFOld + (LFHF))/2);
    LFHFOld = LFHF;
  }
}
