#include <Wire.h>

#include "Arduino.h"
#include "NCP5623.h"

static const uint8_t NCP5623_ILED_MAP[31] = { // NCP5623_ILED_MAP[CURRENT] = REG_VALUE; // Mapped from table 3 of datasheet (https://www.onsemi.com/pub/Collateral/NCP5623-D.PDF)
    0, 4, 17, 22, 24, 25, 26, 27, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31
};

NCP5623::NCP5623() {
    _addr = NCP5623_DEFAULT_ADDR;
    _red = 0;
    _green = 1;
    _blue = 2;
}

void NCP5623::begin() {
    Wire.begin();
    setCurrent(30); // this is reset to zero for some reason
    setColor(0,0,0);
}

void NCP5623::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    setRed(red);
    setGreen(green);
    setBlue(blue);
}

void NCP5623::setRed(uint8_t value) {
    setChannel(_red,(value>>3));
}

void NCP5623::setGreen(uint8_t value) {
    setChannel(_green,(value>>3));
}

void NCP5623::setBlue(uint8_t value) {
    setChannel(_blue,(value>>3));
}

void NCP5623::setChannel(uint8_t channel, uint8_t value) {
    writeReg(NCP5623_REG_CHANNEL_BASE+channel, value);
}

void NCP5623::writeReg(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(_addr);
    Wire.write(((reg&0x7)<<5)|(value&0x1f)); // rrrvvvvv
    Wire.endTransmission();
}

void NCP5623::setCurrent(uint8_t iled) {
    iled = (iled>30)?30:iled;

    writeReg(NCP5623_REG_ILED, NCP5623_ILED_MAP[iled]);
}

void NCP5623::mapColors(uint8_t red, uint8_t green, uint8_t blue) {
    _red = red;
    _green = green;
    _blue = blue;
}