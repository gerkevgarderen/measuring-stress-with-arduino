/** This function contains all the code required to calculate the stress levels from the readings. */

void Fourier(){ 
 
 // Check if we have enough data for Fourier transform 
 // if not enough, add current reading to the array
 if (dataCount < FHT_N-1){
    dataCount++;
    data[dataCount] = IBI;
  }
 // If enough data is gathered, continue with calculation
  else{

    // Shift all previous readings backwards
    // Effectively making the array act like a stack
    for (int i = 0 ; i < FHT_N-1 ; i++) {
      data[i] = data[i+1];
    }

    // And add current reading as last item in the list
    data[FHT_N-1]=IBI;
    
    // Loop over readings and send to FHT input array
    for (int i = 0 ; i < FHT_N ; i++) {
      fht_input[i] = data[i];
    }
    
    noInterrupts();     // Temporarily stop the interrupts to allow the calculation to run
    fht_window(); 	// window the data for better frequency response
    fht_reorder(); 	// reorder the data before doing the fht
    fht_run(); 		// process the data in the fht
    fht_mag_log(); 	// get the output of the fht, saved to ˋfht_log_outˋ
    interrupts();	// Re-enable the interrupts to continue gathering new readings

    // Reset LF and HF
    LF = 0;
    HF = 0;
	  
    // Get the right bins for LF: 2, 3 & 4 (zero indexed)
    for (int a = 2; a < 5; a++){
      LF += fht_log_out[a];
    }
    // Divide by number of bins to get average of the frequency range
    LF=LF/3;

    // Get the HF bins: 6-11
    for (int a = 6; a < 12; a++){
      HF += fht_log_out[a];
    }
    // Also divide by number of bins to get average of the whole HF range
    HF=HF/6;

    LFHF=LF/HF;
    //Serial.println(LF);
    //Serial.println(HF);
    //Serial.println(LFHF);

    vibeTimeSet = 500*((LFHFOld + (LFHF))/2);

    // Store current LF/HF for next calculation
    LFHFOld = LFHF;
  }
}
