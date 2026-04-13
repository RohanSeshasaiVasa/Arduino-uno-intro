#include <LedControl.h>

// DIN, CLK, CS, number of devices
LedControl lc = LedControl(11, 13, 10, 1);

byte maleSymbol[8] = {
  B00011000,
  B00111100,
  B00011000,
  B01111110,
  B00011000,
  B00100100,
  B01000010,
  B00000000
};

void setup() {
  lc.shutdown(0, false);   // Wake up display
  lc.setIntensity(0, 8);   // Brightness (0–15)
  lc.clearDisplay(0);      // Clear display
}

void loop() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, maleSymbol[i]); // Set each row
  }
}
