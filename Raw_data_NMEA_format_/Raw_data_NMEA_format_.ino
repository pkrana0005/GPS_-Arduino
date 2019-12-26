#include <SoftwareSerial.h>   //using "SoftwareSerial" library
SoftwareSerial ss(D8,D7); //object name is "ss" here and pin defined as Rx,Tx respectively
void setup() {         // put your setup code here, to run once:
 Serial.begin(9600);   //intialising serial communication with USB at 9600 bits/sec
 ss.begin(9600);       //intialising serial communication with GPS module at 9600 bits/sec
}

void loop() {                 // put your main code here, to run repeatedly:
 while(ss.available()>0)       //while GPS data is ready to be send to NodeMCU
    {
      byte dataGPS = ss.read();  //reading GPS data and saving it to variable "dataGPS" (data type is "byte")
      Serial.write(dataGPS);     //printing the RAW GPS data on serial monitor
      
      }
}

/* References:-
 *  https://create.arduino.cc/projecthub/ruchir1674/how-to-interface-gps-module-neo-6m-with-arduino-8f90ad
 *  Read NEO 6M GPS module DATA sheet
 *  https://www.gpsworld.com/what-exactly-is-gps-nmea-data/
 */
