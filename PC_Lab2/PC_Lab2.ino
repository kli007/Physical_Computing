int LED=11;
int Dial;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(Dial, INPUT);
}

void loop() {
  Dial=analogRead(A0);
  digitalWrite(LED,HIGH);
  delay(Dial);
  digitalWrite(LED,LOW);
  delay(Dial);
}
