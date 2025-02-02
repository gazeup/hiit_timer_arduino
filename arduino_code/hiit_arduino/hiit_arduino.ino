const int hiitLedPin = 3;
const int pausLedPin = 4;
const int soundPin = 8;

void setup() {
  Serial.begin(9600);

  pinMode(hiitLedPin, OUTPUT);
  pinMode(pausLedPin, OUTPUT);
  pinMode(soundPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int active_time, pause_time, rounds;

    if (sscanf(data.c_str(), "%d,%d,%d", &active_time, &pause_time, &rounds) == 3) {
    
      active_time *= 1000; // time is received in seconds and need to be in ms
      pause_time *= 1000;

      for (int i = 0; i < rounds; i++) {
        delay(10);
        digitalWrite(hiitLedPin, HIGH);
        delay(active_time);
        digitalWrite(hiitLedPin, LOW);
        digitalWrite(pausLedPin, HIGH);
        delay(pause_time);
        digitalWrite(pausLedPin, LOW);
      }
    }
  }
}