#include <SoftwareSerial.h>     //using "SoftwareSerial" library
#include <TinyGPS++.h>          //using "TinyGPS" library

SoftwareSerial ss(D8,D7);        //object name is "ss" here and pin defined as Rx,Tx respectively
TinyGPSPlus gps;          //object name is "gps" here
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);        //intialising serial communication with USB at 9600 bits/sec
ss.begin(9600);             //intialising serial communication with GPS module at 9600 bits/sec
}

void loop() {
  // put your main code here, to run repeatedly:
while(ss.available()>0)  //while GPS data is ready to be send to NodeMCU
    {
      gps.encode(ss.read());    //aringing(encoding)(or converting) the read data into suitable format
      if(gps.location.isUpdated()){

         Serial.print("Sat Count = ");
         Serial.print(gps.satellites.value());
         Serial.print("   Date = ");
         Serial.print(gps.date.value());
         Serial.print("   Time = ");
         Serial.print(gps.time.value());
         Serial.print("   Lat = ");
         Serial.print(gps.location.lat(),4);
         Serial.print("   Long = ");
         Serial.print(gps.location.lng(),4);
         Serial.print("   Speed (mps)= ");
         Serial.println(gps.speed.mps());
         
         }
      }

}

/* References:-
 * 
 * https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/
 * http://arduiniana.org/libraries/tinygpsplus/
 */
