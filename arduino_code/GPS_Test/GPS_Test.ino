#include <TinyGPS++.h>

#include <SoftwareSerial.h>

SoftwareSerial ss(4,3);
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ss.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  while (ss.available() > 0) {
    gps.encode(ss.read());
    Serial.println(gps.location.lng());
//    byte gpsData = ss.read();
//    Serial.write(gpsData);
  }
}
