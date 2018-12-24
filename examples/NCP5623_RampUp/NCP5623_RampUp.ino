#include <NCP5623.h>

#define COLOR_DURATION 5000   // Color ramp up duration
#define DELAY_INTERVAL (COLOR_DURATION>>5)    // Delay between color increments
#define COLOR_MAX 0x1f    // Maximum color value
#define STATE_MAX 7   // Maximum colors

NCP5623 rgb;

uint8_t val,cstate;

void setup() {
  val = 0;
  cstate = 1; // start off on blue
  rgb.begin();
  //rgb.mapColors(2,1,0); // use BGR instead of RGB; I needed this for my design
}

void loop() {
  uint8_t r,g,b;

  r = (cstate & 4)?val<<3:0; // Red channel enabled on cstate = 4,5,6,7  // val<<3 adjusts from 5 bit quantity to 8 bit for the library
  g = (cstate & 2)?val<<3:0; // Green channel enabled on cstate = 2,3,6,7
  b = (cstate & 1)?val<<3:0; // Blue channel enabled on cstate = 1,3,5,7
  rgb.setColor(r,g,b);
  delay(DELAY_INTERVAL);
  val++;
  if (val>COLOR_MAX) { // if val has reached max,
    val = 0;  // reset val
    cstate++; // next state
    if (cstate > STATE_MAX) { // if state has reached max
      cstate = 0; // reset state
    }
  }
}
