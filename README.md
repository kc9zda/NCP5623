# NCP5623

The NCP5623 is an I2C RGB LED driver chip from ON Semiconductor. This library provides basic support for setting the colors of the individual channels. It does not support the built-in hardware dimming.

# Installation

1. Download this repository as a zip file.
2. Extract the zip file into the "libraries/" folder of your Arduino sketchbook folder. Verify that there is a folder called "NCP5623" (or something similar) and within that, there are the source files (NCP5623.cpp and NCP5623.h) and the "examples/" folder.

Alternatively, you can clone the repository directly into the "libraries/" folder of your Arduino sketchbook folder. 

# Usage

The library provides a NCP5623 class, which allows communication to the NCP5623 IC.

This class provides the following methods:

 - `begin();` - Call this in your "setup" function to initialize the IC.
 - `setColor(uint8_t red, uint8_t green, uint8_t blue);` - Set the intensity of the red, green, and blue LED channels. This function accepts integers from 0 to 255, however the NCP5623 only accepts values from 0-31, so some resolution is lost.
 - `setCurrent(uint8_t ma);` - Set the maximum allowed current per channel. `ma` is in milliamps. Current based on 62k&#937; resistor between IREF (pin 10) and ground. For more precise control, use `writeReg(NCP5623_REG_ILED, /*some value*/);` See the [datasheet](https://www.onsemi.com/pub/Collateral/NCP5623-D.PDF) for the proper values to write to this register.
 - `setChannel(uint8_t channel, uint8_t value);` - Sets the PWM value (0-31) of a particular channel.
 - `setRed(uint8_t value);` - Sets the intensity (0-255) of the red channel
 - `setGreen(uint8_t value);` - Sets the intensity (0-255) of the green channel
 - `setBlue(uint8_t value);` - Sets the intensity (0-255) of the blue channel
 - `writeReg(uint8_t reg, uint8_t value);` - Writes `value` (0-31) to `reg` (0-7)
 - `mapColors(uint8_t red, uint8_t green, uint8_t blue);` - Each parameter specifies which channel controls which color.

 # Channels

 | Channel | Pin | Default color mapping |
 | --- | --- | --- |
 | 0 | 5 | Red |
 | 1 | 4 | Green |
 | 2 | 3 | Blue |

 Use `mapColors` to map the channels to different colors. 
 Most functions accept 8 bit color values. These values are reduced to 5 bits by shifting right.