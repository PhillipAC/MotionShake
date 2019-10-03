//Device will detect motion at which point it will move a motor between 0 degress 
//and 180 degrees every half second. 

#include <Servo.h>
Servo servo;
 
int sensor = 2; //The pin the sensor is connected to
int servoPin = 12; //The pins the motor is set to
int motorPositions[] = {0,180}; //The extreme positions of the motor for shaking
int val = 0; //The read from the sensor
int duration = 10; //How many seconds the vibrations will last in total
int coolDown = 10; //How many seconds the device will wait before look for motion

void setup() {
  //Set the pin for the motor
  servo.attach(servoPin);
  //Set the sensor pin to input
  pinMode(sensor, INPUT);  
  servo.write(90);
}

void loop(){ 
  //Check the sensor
  val = digitalRead(sensor);
  //If the sensor returns HIGH begin to vibrate 
  if (val == HIGH) {
    vibrate(duration);
    //Allow time before the vibration can be triggered again
    delay(coolDown * 1000);          
  } 
}

void vibrate(int totalDuration){
  int index = 0;
  for(int i = 0; i < totalDuration * 2; i++){
    index = i % 2;
    servo.write(motorPositions[index]);
    delay(500);  
  }
  servo.write(90);
}
