#include <Servo.h>

Servo throttle, elevator, rudder, aileron;

float Gear;
int x = 0, trigger = 0;

void setup(){
  pinMode(11, INPUT);//set input pins
  
  throttle.attach(A0);//set servo output pins
  elevator.attach(A1);
  rudder.attach(A2);
  aileron.attach(A3);
  
  Serial.begin(115200);//Output to Serial when connected to computer
}

void loop() {
  //float Gear;
  
  Gear = pulseIn(11,HIGH);//receive gear switch input

  if (Gear > 1500){
    manualControl();
  }
  else{
    autoControl();
  }
  
  Serial.print("Gear input: ");
  Serial.println(Gear);
}

void manualControl(){
  Serial.print("Manual Mode- ");
}

void autoControl(){
  if(trigger = 1){
    x = 0;
    trigger = 0;
  }
  //else{
   //x = x - 1;
  //}
  
   if(x >= 180){
    trigger = 1;
    }
   //else{
   // trigger = 0;
   //}
  
  Serial.print("Auto Mode- ");
aileron.write(x);
}
