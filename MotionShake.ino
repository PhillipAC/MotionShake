//Device will detect motion at which point it will cycle through vibrator motors for one second
//each. After the duration is reached the device will pause for the duration of the cool down.


int sensor = 2; //The pin the sensor is connected to
int vibrators[] = {11,12}; //The pins the vibrator motors are set to
int vibLength = sizeof(vibrators)/sizeof(int); //How many vibrator motors exist
int val = 0; //The read from the sensor
int duration = 6; //How many seconds the vibrations will last in total
int coolDown = 5; //How many seconds the device will wait before look for motion

void setup() {
  //Set each vibrartor pin to output
  for(int i = 0; i < vibLength; i++)
  {
    pinMode(vibrators[i], OUTPUT);
  }
  //Set the sensor pin to input
  pinMode(sensor, INPUT);  
}

void loop(){
  //Check teh sensor
  val = digitalRead(sensor);
  //If the sensor returns HIGH begin to vibrate 
  if (val == HIGH) {
    vibrate(6);
    //Allow time before the vibration can be triggered again
    delay(5000);          
  } 
}

void vibrate(int totalDuration){
  int pin = 0;
  for(int i = 0; i < totalDuration; i++){
    pin = i % vibLength;
    digitalWrite(vibrators[pin], HIGH);
    delay(1000);
    digitalWrite(vibrators[pin], LOW);  
  }
}
