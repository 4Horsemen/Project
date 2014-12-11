
#include <Servo.h>  // servo library
Servo servo1;  // servo control object

const int button1Pin = 2;  // pushbutton 1 pin

const int ledPin =  13;    // LED pin
const int motorPin = 7;

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1Pin, INPUT);

  // Set up the LED pin to be an output:
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);  
  servo1.attach(9);
  Serial.begin(9600);
}

  void loop()
{
  int counter=0;
  int button1State;  // variables to hold the pushbutton states
  
  button1State = digitalRead(button1Pin);
 while(counter<4)
 {
  if (button1State == LOW) // pushing button 1                                                      // then...
  {
    digitalWrite(ledPin, HIGH);  // turn the LED on
    //delay(1000); 
    servo1.write(90);
    counter++;
  }
    else
  {
  servo1.write(20);
  digitalWrite(ledPin, LOW);
  digitalWrite(motorPin, LOW); 
  }
 }
digitalWrite(motorPin, HIGH);
 
}
