int LED=11;

void setup() {
  pinMode(LED, OUTPUT);

}

void loop() {
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(1000);
}
