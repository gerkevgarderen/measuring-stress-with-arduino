/*  Heart sensor code is based on: Pulse Sensor Amped 1.4 by Joel Murphy and Yury Gitman of http://www.pulsesensor.com
 *  For the original Pulse Sensor Amped code and license of said code, please see: https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/LICENSE
 */

 /*
  * This edited and extended version of code was written by Gerke van Garderen, https://gerkevangarderen.nl/
  * It was written as an extension of beformentioned code, to add stress sensing through monitoring of Heart Rate Variability (HRV)
  * 
  * Note: because the sensor code makes use of Timer2, pins 3 and 11 lose PWM-functionality.
  */

#define LOG_OUT 1 // use the log output function
#define FHT_N 32 // set to 256 point fht

#include <FHT.h> // include the library for Fourier transform

#define vibrationPin 5
boolean vibing = true; //checks whether vibration is currently on
boolean silence = false;
long vibeTimeSet = 500;
long vibeTimer = 0;

float HF=0;
float LF=0;
float LFHF,LFHFOld;


//  Variables
//int sensorVcc = 12;
int pulsePin = A0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

int data[32];
int dataCount = 0;
boolean once = false;

void setup(){
 // pinMode(sensorVcc,OUTPUT);
 // digitalWrite(sensorVcc,HIGH);
  
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!

  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 


}


//  Where the Magic Happens
void loop(){
  
    //serialOutput() ;       
    
  if (QS == true){                      // A Heartbeat Was Found, BPM and IBI have been Determined. Quantified Self "QS" is set to true when arduino finds a heartbeat
        serialOutputWhenBeatHappens();  // A Beat Happened, Output that to serial. 
        Fourier();                      // Run the Fourier code to calculate HF/LF    
        QS = false;                     // reset the Quantified Self flag for next time    
  }
  delay(10);                             //  take a break
}




