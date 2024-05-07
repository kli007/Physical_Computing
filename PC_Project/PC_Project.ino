#include <math.h>
int dial=A0;
double y=25;
double x=25;
double speed=0;

int roundY;
int roundX;

int Switch=8;
int speedButton=4;

double timer;

bool reset=true;
bool count=true;

int goal[2]={};
int goalLarge[4]={};

void setup() {
  pinMode(dial, INPUT);
  pinMode(Switch, INPUT);
  pinMode(speedButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(Switch)==1){ 
   countdown();
   Serial.print(timer);
    Serial.println(" seconds left!");
    if(timer>0){
      timer=timer-.5;
      changeSpeed();
      drive(); 
      hint();
      reset=true;
    }  
    else{
      Serial.println("You Lose! Flip the Switch!");
    }
  }
  else if(reset==true){
    position();
    newGame();
  }
  delay(500);
}

void hint(){
  unsigned int xDistance=roundX-goal[0];
  unsigned int yDistance=roundY-goal[1];
  unsigned int distance=(sq(xDistance)+sq(yDistance));
  distance=sqrt(distance);
  Serial.print("Distance From Target:");
  Serial.println(distance);
  Serial.println();
  Serial.println();
}

void newGame(){
  count=true;
  timer=60;
  x=25;
  y=25;
}
