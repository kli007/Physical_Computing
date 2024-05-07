#include <Servo.h>
int temp=A0;
Servo servo1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(temp, INPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  servo1.attach(6);
}

void loop() {
  // put your main code here, to run repeatedly:
  int number=((analogRead(temp)*(5000/1024))-500)/10;
  Serial.print("Tempature: ");
  Serial.println(number);
  delay(150);
  if(number<=10){
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  else if (number<=30){
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  else{
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
  }
  servo1.write(number*5);
  delay(333);
}
