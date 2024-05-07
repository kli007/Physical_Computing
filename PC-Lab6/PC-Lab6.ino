int volt=A0;
unsigned long time;
unsigned long prevTime;


void setup() {
  pinMode(volt, INPUT);
  Serial.begin(9600);
}

void loop() {
  time=millis();
  if (time-prevTime>=1500){
    float measure=(analogRead(volt)/1023.0)*5.0;
    Serial.print("Voltage: ");
    Serial.println(measure);
    prevTime=millis();
  }
}
