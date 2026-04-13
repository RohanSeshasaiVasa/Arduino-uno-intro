#include <TM1637Display.h>

// TM1637 pins
#define CLK 3
#define DIO 2

// Buzzer pin
#define BUZZER 8

TM1637Display display(CLK, DIO);

int count = 1;

void setup() {
  display.setBrightness(7);   // Brightness (0–7)
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  // Show number (no leading zeros)
  display.showNumberDec(count, false);

  // -------- SOUND LOGIC --------
  if (count == 10) {
    // Long beep for 10
    tone(BUZZER, 1000);   // Frequency: 1kHz
    delay(800);           // Long duration
    noTone(BUZZER);
  } else {
    // Short beep for 1–9
    tone(BUZZER, 1000);
    delay(150);           // Short duration
    noTone(BUZZER);
  }

  // Delay before next number
  delay(500);

  // Increment count
  count++;

  // Reset after 10
  if (count > 10) {
    count = 1;
  }
}
