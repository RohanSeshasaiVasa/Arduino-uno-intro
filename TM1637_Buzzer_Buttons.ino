#include <TM1637Display.h>

// Display pins
#define CLK 3
#define DIO 2

// Components
#define BUZZER 8
#define BUTTON 4

TM1637Display display(CLK, DIO);

int count = 1;
bool lastButtonState = HIGH;

void setup() {
  display.setBrightness(7);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); // important
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON);

  // Detect button press (HIGH → LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {

    // Show number
    display.showNumberDec(count, false);

    // ---- SOUND ----
    if (count == 10) {
      tone(BUZZER, 1000);
      delay(800);   // long beep
      noTone(BUZZER);
    } else {
      tone(BUZZER, 1000);
      delay(150);   // short beep
      noTone(BUZZER);
    }

    // Increment
    count++;

    if (count > 10) {
      count = 1;
    }

    delay(200); // simple debounce
  }

  lastButtonState = currentButtonState;
}
