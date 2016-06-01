void Fourier(){ 
 if (dataCount < 31){
    dataCount++;
    data[dataCount] = IBI;
  }
  else{        
    for (int i = 0 ; i < FHT_N-1 ; i++) { // save 256 samples
      data[i] = data[i+1];
    }
    data[31]=IBI;
    for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
      fht_input[i] = data[i]; // put real data into bins
    }
    //for (int i = 0 ; i < FHT_N ; i++) { // save 256 samples
     // Serial.println(fht_input[i]); // put real data into bins
    // }

    Serial.println("Calculating..");
    noInterrupts();
    fht_window(); // window the data for better frequency response
    fht_reorder(); // reorder the data before doing the fht
    fht_run(); // process the data in the fht
    fht_mag_log(); // take the output of the fht
    interrupts();
      
    for (int a = 2; a < 5; a++){
      LF += fht_log_out[a];
    }
    
    for (int a = 6; a < 12; a++){
      HF += fht_log_out[a];
    }
    LF=LF/3;
    HF=HF/6;
    //Serial.println(LF);
    //Serial.println(HF);
    Serial.println(LF/HF);

    vibing = true;
    vibeTime = (50*(LF/HF));
    analogWrite(vibrationPin,255);
  }
}
