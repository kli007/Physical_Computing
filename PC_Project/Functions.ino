void drive(){
  int theta=(analogRead(dial))/2.84;
  delay(250);
  double deltaY=speed*(sin(theta*(6.28/360)));
  double deltaX=speed*(cos(theta*(6.28/360)));
  y=y+deltaY;
  roundY=round(y);
  if(roundY>50){
    roundY=50;
    y=50;
  }
  if(roundY<1){
    roundY=1;
    y=1;
  }
  x=x+deltaX;
  roundX=round(x);
  if(roundX>50){
    roundX=50;
    x=50;
  }
  if(roundX<1){
    roundX=1;
    x=1;
  }
  Serial.print(theta);
  Serial.print(" degrees, Position:(");
  Serial.print(roundX);
  Serial.print(", ");
  Serial.print(roundY);
  Serial.print("), Speed: ");
  Serial.println(speed);
}

void position(){
  roundY=round(y);
  roundX=round(x);
  Serial.println();
  for(int yP=50; yP>=1; yP--){
    for(int xP=1; xP<=50; xP++){
      if((xP==roundX)&&(yP==roundY)){
        Serial.print("x  ");
      }
      else if((xP>=goalLarge[0])&&(xP<=goalLarge[1])&&(yP>=goalLarge[2])&&(yP<=goalLarge[3])){
        Serial.print("   ");
      }
      else{
        Serial.print("0  ");
      } 
    } 
    Serial.print("|");   
    Serial.print(yP);
    Serial.println("");
  }
  for(int space=0; space<=50; space++){
    Serial.print("___");
  }
  Serial.println();
  for(int format=1; format<=9; format++){
    Serial.print(format);
    Serial.print("  ");
  }
  for(int format=10; format<=50; format++){
    Serial.print(format);
    Serial.print(" ");
  }
  Serial.println("");
  if((roundX>=goalLarge[0])&&(roundX<=goalLarge[1])&&(roundY>=goalLarge[2])&&(roundY<=goalLarge[3])){
    Serial.print("You Win! Remaining Time: "); 
    Serial.print(timer);
    Serial.println(" seconds");
  } 
  Serial.print("The goal was at (");
  Serial.print(goal[0]);
  Serial.print(", ");
  Serial.print(goal[1]);
  Serial.println("). Flip the switch to try again");
  Serial.println("");
  reset=false;
}

void countdown(){
  if (count==true){
    Serial.println("3");
    Serial.println();
    delay(1000);
    Serial.println("2");
    Serial.println();
    delay(1000);
    Serial.println("1");
    Serial.println();
    delay(1000);
    count=false;
    goal[0]=random(3,49);
    goal[1]=random(3,49);
    goalLarge[0]=goal[0]-2;
    goalLarge[1]=goal[0]+2;
    goalLarge[2]=goal[1]-2;
    goalLarge[3]=goal[1]+2;
  }
}

void changeSpeed(){
  if(digitalRead(speedButton)==LOW){
    speed=2;
  }
  else{
    speed=0;
  }
}