//Device will detect motion at which point it will move a motor between 0 degress 
//and 180 degrees every half second. 

#include <Servo.h>
#include "pitches.h"

Servo servo;
 
int sensor = 2; //The pin the sensor is connected to
int servoPin = 12; //The pins the motor is set to
int motorPositions[] = {0,180}; //The extreme positions of the motor for shaking
int val = 0; //The read from the sensor
int duration = 40; //How many times will the device oscillate
int coolDown = 10; //How many seconds the device will wait before look for motion
int noteDuration = 150; //Duration of each note
int pauseBetweenNotes = noteDuration * 1.30; //Pause between notes
    
// notes in the melody:
int melody[] = {
  NOTE_CS5,NOTE_FS4,NOTE_FS4,NOTE_CS5,NOTE_FS4,NOTE_FS4,NOTE_CS5,NOTE_FS4,NOTE_D5,NOTE_FS4 
};

void setup() {
  //Set the pin for the motor
  servo.attach(servoPin);
  //Set the sensor pin to input
  pinMode(sensor, INPUT);  
  servo.write(90);
}

void playMelody(int note){
    tone(8, melody[note], noteDuration);
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
}

void oscillate(int totalDuration){
  int index = 0;
  int note = 0;
  for(int i = 0; i < totalDuration; i++){
    index = i % 2;
    note = i % 10;
    servo.write(motorPositions[index]);
    playMelody(note);
  }
  servo.write(90);
}

void loop(){ 
  //Check the sensor
  val = digitalRead(sensor);
  //If the sensor returns HIGH begin to vibrate 
  if (val == HIGH) {
    oscillate(duration);
    //Allow time before the vibration can be triggered again
    delay(coolDown * 1000);          
  } 
}
