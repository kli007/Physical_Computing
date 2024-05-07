int redLED=11;
int blueLED=9;
int greenLED=10;
int redVal=128;
int blueVal=128;
int greenVal=128;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  int sign=random(0,1);
  int value=random(1,25);
  if(redVal>=245||redVal<10){
    redVal=128;
  }
  else {
    if(sign==1) {
      redVal=redVal+value;
    }
    else {
      redVal=redVal-value;
    } 
  }
  sign=random(0,1);
  value=random(1,25);
  if(greenVal>=245||greenVal<10){
    greenVal=128;
  }
  else {
    if(sign==1) {
      greenVal=greenVal+value;
    }
    else {
      greenVal=greenVal-value;
    } 
  }
  sign=random(0,1);
  value=random(1,25);
  if(blueVal>=245||blueVal<10){
    blueVal=128;
  }
  else {
    if(sign==1) {
      blueVal=blueVal+value;
    }
    else {
      blueVal=blueVal-value;
    } 
  }

  analogWrite(redLED,redVal);
  analogWrite(greenLED,greenVal);
  analogWrite(blueLED,blueVal);
  delay(500);
}
