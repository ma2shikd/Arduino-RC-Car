const int LEDGREEN = 7; // LED connected to digital pin 13

const int motorApinA =2;

const int motorApinB =4;

const int motorBpinA =8;

const int motorBpinB =12;

const int motorCpinA =3;

const int motorCpinB =5;

const int motorDpinA =6;

const int motorDpinB =9;

const int ENA = A0;

const int ENB = A1;

const int ENC = A2;

const int END = A5;

const int triggerpin = 13;

const int echopin = 10;

const int speaker = A3;

#include <Servo.h>

Servo servo;

char receivedChar = '0';

int cm = 0;


long readUltrasonicDistance(int triggerPin, int echoPin)

{

  pinMode(triggerpin, OUTPUT);  // Clear the trigger

  digitalWrite(triggerpin, LOW);

  delayMicroseconds(2);

  // Sets the trigger pin to HIGH state for 10 microseconds

  digitalWrite(triggerpin, HIGH);

  delayMicroseconds(10);

  digitalWrite(triggerpin, LOW);

  pinMode(echopin, INPUT);

  // Reads the echo pin, and returns the sound wave travel time in microseconds

  return pulseIn(echopin, HIGH);

}


void setup() {

  Serial.begin(9600);  // Set the baud rate to match both Arduino boards

  pinMode(LEDGREEN, OUTPUT);

  pinMode(motorApinA, OUTPUT);

  pinMode(motorApinB, OUTPUT);

  pinMode(motorBpinA, OUTPUT);

  pinMode(motorBpinB, OUTPUT);

  pinMode(motorCpinA, OUTPUT);

  pinMode(motorCpinB, OUTPUT);

  pinMode(motorDpinA, OUTPUT);

  pinMode(motorDpinB, OUTPUT);

  pinMode(triggerpin,OUTPUT);

  pinMode(echopin,INPUT);

  servo.attach(11);

  servo.write(90);


}


void loop() {

  cm = 0.01723 * readUltrasonicDistance(13, 10);

  

  if (Serial.available() > 0) {

    receivedChar = Serial.read();

  }

    if (receivedChar == 'H') {

      digitalWrite(LEDGREEN,HIGH); 

      analogWrite(ENB,255);

      analogWrite(ENA,255);

      digitalWrite(motorApinA,LOW);

      digitalWrite(motorApinB,HIGH);

      digitalWrite(motorBpinA,HIGH);

      digitalWrite(motorBpinB,LOW);

      analogWrite(ENC,255);

      analogWrite(END,255);

      digitalWrite(motorCpinA,LOW);

      digitalWrite(motorCpinB,HIGH);

      digitalWrite(motorDpinA,HIGH);

      digitalWrite(motorDpinB,LOW);

    }

    if (receivedChar == 'J') {

      digitalWrite(LEDGREEN,HIGH); 

      analogWrite(ENB,255);

      analogWrite(ENA,255);

      digitalWrite(motorApinA,HIGH);

      digitalWrite(motorApinB,LOW);

      digitalWrite(motorBpinA,LOW);

      digitalWrite(motorBpinB,HIGH);

      analogWrite(ENC,255);

      analogWrite(END,255);

      digitalWrite(motorCpinA,HIGH);

      digitalWrite(motorCpinB,LOW);

      digitalWrite(motorDpinA,LOW);

      digitalWrite(motorDpinB,HIGH);

    }


    if (receivedChar == 'G') { 

      digitalWrite(LEDGREEN,HIGH); 

      analogWrite(ENB,255);

      analogWrite(ENA,255);

      digitalWrite(motorApinA,LOW);

      digitalWrite(motorApinB,HIGH);

      digitalWrite(motorBpinA,LOW);

      digitalWrite(motorBpinB,LOW);

      analogWrite(ENC,255);

      analogWrite(END,255);

      digitalWrite(motorCpinA,LOW);

      digitalWrite(motorCpinB,LOW);

      digitalWrite(motorDpinA,HIGH);

      digitalWrite(motorDpinB,LOW);

      servo.write(0);

    }


     if (receivedChar == 'F') {

      digitalWrite(LEDGREEN,HIGH); 

      analogWrite(ENB,255);

      analogWrite(ENA,255);

      digitalWrite(motorApinA,LOW);

      digitalWrite(motorApinB,LOW);

      digitalWrite(motorBpinA,HIGH);

      digitalWrite(motorBpinB,LOW);

      analogWrite(ENC,255);

      analogWrite(END,255);

      digitalWrite(motorCpinA,LOW);

      digitalWrite(motorCpinB,HIGH);

      digitalWrite(motorDpinA,LOW);

      digitalWrite(motorDpinB,LOW);

      servo.write(180);

     }


     if (cm < 10){

      tone(speaker, 400); // Send 1KHz sound signal...

      delay(300);         // ...for 1 sec

      noTone(speaker);     // Stop sound...

      delay(700);         // ...for 1sec

      

     }


     if (cm >= 10){

      noTone(speaker);

     }



      if (receivedChar == 'L') {

      digitalWrite(LEDGREEN,LOW); 

      analogWrite(ENB,0);

      analogWrite(ENA,0);

      digitalWrite(motorApinA,LOW);

      digitalWrite(motorApinB,LOW);

      digitalWrite(motorBpinA,LOW);

      digitalWrite(motorBpinB,LOW);

      analogWrite(ENC,0);

      analogWrite(END,0);

      digitalWrite(motorCpinA,LOW);

      digitalWrite(motorCpinB,LOW);

      digitalWrite(motorDpinA,LOW);

      digitalWrite(motorDpinB,LOW);

      servo.write(90);


    }

   

}