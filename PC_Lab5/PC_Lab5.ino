const int ledOne[]={3,2,6,7};
const int button=8;

void setup(){
  for (int i=0;i<=3;i++){
    pinMode(ledOne[i], OUTPUT);
  }
  pinMode(button,INPUT);
  digitalWrite(ledOne[1],HIGH);
  digitalWrite(ledOne[2],HIGH);
}

void loop(){
  if(digitalRead(button)==HIGH){
    analogWrite(ledOne[0],200);
    delay(5000);
    digitalWrite(ledOne[1],LOW);
    digitalWrite(ledOne[0],HIGH);
    digitalWrite(ledOne[2],LOW);
    digitalWrite(ledOne[3],HIGH);
    delay(30000);
    analogWrite(ledOne[2],200);
    delay(5000);
    digitalWrite(ledOne[3],LOW);
    digitalWrite(ledOne[2],HIGH);
    digitalWrite(ledOne[0],LOW);
    digitalWrite(ledOne[1],HIGH);
  }
  delay(150);
}