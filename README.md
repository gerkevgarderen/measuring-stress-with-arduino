# Sensing Stress with Arduino
_Using a Heart Beat Sensor to measure stress levels in the human body_

This edited and extended version of code was written by Gerke van Garderen, https://gerkevangarderen.nl/.
It is written as an extension of existing heart rate sensor code, to add stress sensing through monitoring of Heart Rate Variability (HRV).

**Heart rate sensor code is copied from: Pulse Sensor Amped 1.4** by Joel Murphy and Yury Gitman of http://www.pulsesensor.com.
I only added the HRV functionality and biofeedback, and shortened their original code to save resources.
For the original Pulse Sensor Amped code and license of said code, please see: https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino/blob/master/

**Note: because the sensor code makes use of Timer2, pins 3 and 11 lose PWM-functionality.**
