
#include <Servo.h>  // servo library
Servo servoL;  // lid servo control object
Servo servoA; //arm servo

const int motor1Pinin1 = 6; //first motor controller input 1
const int motor1Pinin2 = 5; //first motor controller input 2
const int motor2Pinin1 = 8; //2nd motor controller input 1
const int motor2Pinin2 = 7; //2nd motor controller input 2

//initializes counter to counter number of times switch toggles to high
int count = 0; 
void setup()
{
  // Set up the switch pin to be an input:
  pinMode(A1, INPUT);

  pinMode(motor1Pinin1, OUTPUT); //sets up motor controllers
  pinMode(motor1Pinin2, OUTPUT);  
  pinMode(motor2Pinin1, OUTPUT);  
  pinMode(motor2Pinin2, OUTPUT);  
  servoL.attach(3); //attach lid and arm servos to pins
  servoA.attach(4);
  Serial.begin(57600); //begin at correct baud rate
}

  void loop()
{
 
  int toggle = 0;  // variables to hold the switch states

//set all motor controllers to low to ready for standby
  digitalWrite(motor1Pinin1, LOW); 
  digitalWrite(motor1Pinin2, LOW); 
  digitalWrite(motor2Pinin1, LOW); 
  digitalWrite(motor2Pinin2, LOW);

  servoL.write(70); //set lid servo to 70 degrees
  servoA.write(20); //set arm servo to 20 degrees
  
  //press toggle switch up to this much, box turns itself off
 while (count < 4) 
  {
    toggle = digitalRead(A1);
    if (toggle == HIGH)
    {
     servoL.write(35); //lid opens first
     delay(1500); //wait for it...
     servoA.write(170); //arm pops out and hits switch back
     delay(1000); //give it time to go back in
     servoA.write(20); //arm goes back in
     delay(2000); //keep lid open for theatrics
     servoL.write(70); //close lid
     delay(1000);
     count++; //keep track of # of times switched
     delay(1000); 
  }
}
//after a certain amount of switches, box gets mad
 if (count >= 4)
  {
    //values needed to turn on motor controllers to "spin" box
    digitalWrite(motor1Pinin1, HIGH); 
    digitalWrite(motor1Pinin2, LOW);
    digitalWrite(motor2Pinin1, LOW);
    digitalWrite(motor2Pinin2, HIGH);
    delay(5000); //give it time to be mad
    digitalWrite(motor1Pinin1, LOW); //turn off motors
    digitalWrite(motor1Pinin2, LOW); 
    digitalWrite(motor2Pinin1, LOW); 
    digitalWrite(motor2Pinin2, LOW); 
   count = 0; //reset to start all over again
  } 
}
