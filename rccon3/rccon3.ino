float ch1; // Here's where we'll keep our channel values
float ch2;
float f1;
float f2;
float x;
float y;
float r;
float t;
float left;
float right;
float MotorSpeed1;
float MotorSpeed2;

#define Q_PI 0.7853981633974482;

// Motor A LEFT
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B RIGHT
int enB = 3;
int in3 = 10;
int in4 = 4;

void setup() {
  // put your setup code here, to run once:

  pinMode(5, INPUT); // Set our input pins as such
  pinMode(6, INPUT);
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Motor A
  digitalWrite(enA, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  // Motor B
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:


  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of  
  ch2 = pulseIn(6, HIGH, 25000); // each channel
  ch1 = map(ch1, 1000,2000, -500, 500);
  ch2 = map(ch2, 1000,2000, -500, 500);
  ch1 = constrain(ch1, -500, 500);
  ch2 = constrain(ch2, -500, 500);

  //f1 = map(ch1, 1000,2000, -1, 1);
  //f2 = map(ch2, 1000,2000, -1, 1);

  x = ch1/500;
  y = ch2/500;

  //y = y*-1;
  
  r = sqrt(x*x + y*y);
  t = atan2(x,y);

  t = t + Q_PI
  
  left = r* cos(t);
  right = r* sin(t);

  //rescale the new coords
  left = left * sqrt(2);
  right = right * sqrt(2);
  
  // clamp to -1/+1
  left = max(-1, min(left, 1));
  right = max(-1, min(right, 1));


  if(left > 0) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    }else{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    }

  if(right > 0){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }else{
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    }    

  // Set the motor speeds
  MotorSpeed1 = abs(left*255);
  MotorSpeed2 = abs(right*255);
  //Bzuceni motoru
  if (MotorSpeed1 < 25)MotorSpeed1 = 0;
  if (MotorSpeed2 < 25)MotorSpeed2 = 0;
  analogWrite(enA, MotorSpeed1);
  analogWrite(enB, MotorSpeed2);
  
  Serial.print("A:"); //Serial debugging stuff
  Serial.print(left*255);

  Serial.print("B"); //Serial debugging stuff
  Serial.println(right*255);
  
}
