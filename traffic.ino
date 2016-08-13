const int potIntensity = A0, btnChangeLight = 9, btnChangeMode = 8;
enum LIGHT {RED = 5, YELLOW = 4, GREEN = 3};
enum MODE {BLINK, FADE, STAY_ON};
LIGHT currentLight = RED;
MODE currentMode = STAY_ON;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(potIntensity, INPUT);
  pinMode(btnChangeLight, INPUT);
  pinMode(btnChangeMode, INPUT);
}

void resetLights() {
  analogWrite(RED, 0);
  analogWrite(YELLOW, 0);
  analogWrite(GREEN, 0);
}

int pot() {
  return map(analogRead(potIntensity), 0, 1023, 0, 255);
}

bool shouldChangeLight() {
  static bool debounce = false;
  bool light = digitalRead(btnChangeLight);
  if (light && !debounce) {
    debounce = true;
    return true;
  }
  if (!light) debounce = false;
  return false;
}

bool shouldChangeMode() {
  static bool debounce = false;
  bool mode = digitalRead(btnChangeMode);
  if (mode && !debounce) {
    debounce = true;
    return true;
  }
  if (!mode) debounce = false;
  return false;
}

void executeCurrentMode() {
  static int brightness = 0;
  static bool shouldIncrement = true;
  switch(currentMode) {
    case STAY_ON:
      analogWrite(currentLight, pot());
      break;
    case BLINK:
      if (millis() % 250 == 0) {
        brightness = 0;
      }
      if (millis() % 500 == 0) {
        brightness = pot();
      }
      analogWrite(currentLight, brightness);
      break;
    case FADE:
      if (millis() % 20 == 0) {
        if (shouldIncrement) brightness++;
        if (!shouldIncrement) brightness--;
        if (brightness >= 255) shouldIncrement = false;
        if (brightness <= 0) shouldIncrement = true;
      }
      analogWrite(currentLight, brightness);
      break;
  }
}

void loop() {
  // Acquire values
  if (shouldChangeLight()) {
    resetLights();
    switch(currentLight) {
      case RED:
        currentLight = GREEN;
        break;
      case YELLOW:
        currentLight = RED;
        break;
      case GREEN:
        currentLight = YELLOW;
        break;
    }
  }
  if (shouldChangeMode()) {
    switch (currentMode) {
      case STAY_ON:
        currentMode = BLINK;
        break;
      case BLINK:
        currentMode = FADE;
        break;
      case FADE:
        currentMode = STAY_ON;
        break;
    }
  }
  executeCurrentMode();
  if (millis() % 1000 == 0) {
    Serial.println(pot());
  }
}
