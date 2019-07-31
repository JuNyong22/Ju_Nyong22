#include <Servo.h> 
 
int servoPin = 10;

Servo servo; 

int Angle = 0; // servo position in degrees 

void setup() 
{ 
    servo.attach(servoPin); 
} 


void loop() 
{ 
    // scan from 0 to 180 degrees
    for(Angle = 0; Angle < 180; Angle++) 
     { 
        servo.write(Angle); 
        delay(5); 
    } 
    // now scan back from 180 to 0 degrees
    for(Angle = 180; Angle > 0; Angle--) 
    { 
        servo.write(Angle);
        delay(5);
    } 
} 
