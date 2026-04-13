#include <TM1637Display.h>

#define CLK 3
#define DIO 2

TM1637Display display(CLK, DIO);

int count = 1;

void setup() {
  display.setBrightness(7); // 0–7
}

void loop() {
  display.showNumberDec(count);

  count++;

  if (count > 100) {
    count = 1; // restart
  }

  delay(500); // speed of counting
}
