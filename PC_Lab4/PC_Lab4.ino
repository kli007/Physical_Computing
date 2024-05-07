const int ledPin[]={2,3,4,5,6,7,8,9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  for (int x = 0; x <= 7; x++) {
    digitalWrite(ledPin[x], HIGH);
    delay(300);
    digitalWrite(ledPin[x], LOW);
    delay(100);
  }
}
