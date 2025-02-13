const int hiitLedPin = 3;
const int pauseLedPin = 4;
const int soundPin = 8;

void startActiveLight(int active_time) {
  digitalWrite(hiitLedPin, HIGH);
  delay(active_time);
  digitalWrite(hiitLedPin, LOW);
}

void startPauseLight(int pause_time) {
  digitalWrite(pauseLedPin, HIGH);
  delay(pause_time);
  digitalWrite(pauseLedPin, LOW);
}

void startTune() {
  int melody[] = {523, 659, 784};
  int duration[] = {200, 200, 200};

  for (int i = 0; i < 3; i++) {
    tone(soundPin, melody[i]);
    delay(duration[i]);
  }
  noTone(soundPin);
}

void pauseTune() {
  int melody[] = {880, 587};
  int duration[] = {200, 400};

  for (int i = 0; i < 2; i++) {
    tone(soundPin, melody[i]);
    delay(duration[i]);
  }
  noTone(soundPin);
}

void setup() {
  Serial.begin(9600);

  pinMode(hiitLedPin, OUTPUT);
  pinMode(pauseLedPin, OUTPUT);
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
        startTune();
        startActiveLight(active_time);
        pauseTune();
        startPauseLight(pause_time);
      }
    }
  }
}