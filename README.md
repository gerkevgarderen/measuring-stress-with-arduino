# Sensing Stress with Arduino
_Using a Heart Beat Sensor to measure stress levels in the human body_

This project is designed to measure heartbeat with an Arduino with heart beat sensor module.
The Arduino then does a Fast Hartley Transform (FFH, alternative for Fourier) transform to generate the Heart-Rate-Variability (HRV) values.
Based on these values, a relatively accurate indication of the stress levels can be found.

**Background on measuring stress through HRV**

>Thayer, J. F., Åhs, F., Fredrikson, M., Sollers III, J. J., & Wager, T. D. (2012). A meta-analysis of heart rate variability and neuroimaging studies: Implications for heart rate variability as a marker of stress and health. _Neuroscience & Biobehavioral Reviews, 36_(2), 747-756. doi:10.1016/j.neubiorev.2011.11.009

**Background on FFH (the calculation that is used)**

>Piccinin, F., & Department of Defence, South Australia. (1967). _THE FAST HARTLEY TRANSFORM AS AN ALTERNATIVE TO THE FAST FOURIER TRANSFORM _(Technical Memorandum). Retrieved from http://www.dtic.mil/dtic/tr/fulltext/u2/a212493.pdf



This edited and extended version of code was written by Gerke van Garderen, https://gerkevangarderen.nl/.
It is written as an extension of existing heart rate sensor code, to add stress sensing through monitoring of Heart Rate Variability (HRV).


**Heart rate sensor code is copied from: Pulse Sensor Amped 1.4** by Joel Murphy and Yury Gitman of http://www.pulsesensor.com.
For the original Pulse Sensor Amped code and license of said code, please see: 
https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/

Change made:
Added the HRV-calculations and display in the design, as well as shortening of the original Heart Rate Sensor code to preserve resources on the Arduino.

**Note: Code is based on Arduino Pro Mini. If you use a different arduino, some changes to port numbers need to be made.
Also, because this code makes use of Timer2, pins 3 and 11 lose PWM-functionality.**
