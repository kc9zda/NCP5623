#include <NCP5623.h>

NCP5623 rgb;

/* ==== */

void setup() {
  rgb.begin();
  //rgb.mapColors(2,1,0); // Use BGR instead of RGB. I needed this for my design.
}

void loop() {
  rgb.setColor(255,0,0); // Red
  delay(1000);
  rgb.setColor(0,255,0); // Green
  delay(1000);
  rgb.setColor(0,0,255); // Blue
  delay(1000);
  rgb.setColor(0,0,0); // Black
  delay(1000);
}
