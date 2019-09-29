#Motion Shake
--------
This application is designed to allow a series of vibrating motors to 
begin vibrating for one second each for a specified time whenever the
PIR sensor detects motion. 

The program is designed to allow any number of motors; however, the 
current set up uses two motors for a duration of 6 seconds. After 
triggering the program waits 5 seconds before attempting to sense
motion. 

##Setup
1. Connect the PIR sensor's data out to digital pin 2.
2. Connect the PIR sensor's Vin to the 5V pin and the ground to ground pin
3. Connect the first vibrating motor's positive lead to digital pin 11 and ground to ground
4. Connect the second vibrating motor's positive lead to digital pin 12 and ground to ground
5. Connect the Arduino to a power supply (I use a 9v battery).

##Ideas
I created this application with the idea of placing the motors on opposite sides 
of a fake cage I made for halloween. When trick or treaters walk past the cage 
it will shake for several seconds.