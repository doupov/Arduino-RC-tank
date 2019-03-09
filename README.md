# Arduino-RC-tank
Arduino RC control Motor Driver 2A Dual L298 H-Bridge

Simple example how control Motor Driver 2A Dual L298 H-Bridge with 2ch RC receiver


Setup for Motor Driver 2A Dual L298 H-Bridge

// Motor A LEFT
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B RIGHT
int enB = 3;
int in3 = 10;
int in4 = 4;


Setup for analog RC signal
pinMode(5, INPUT);
pinMode(6, INPUT);
