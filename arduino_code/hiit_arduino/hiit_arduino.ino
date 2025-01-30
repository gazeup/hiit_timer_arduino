char userInput;
const int hiitLedPin = 3;
const int pausLedPin = 4;
const int soundPin = 8;
int rounds = 4;

void setup() {
  Serial.begin(9600);

  pinMode(hiitLedPin, OUTPUT);
  pinMode(pausLedPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    userInput = Serial.read();
    
    for (int i = 0; i < rounds; i++) {
      if (userInput == 'o') {
        delay(1000);
        digitalWrite(hiitLedPin, HIGH);
        delay(10000);
        digitalWrite(hiitLedPin, LOW);
        digitalWrite(pausLedPin, HIGH);
        delay(5000);
        digitalWrite(pausLedPin, LOW);
      }
    }
  }
}