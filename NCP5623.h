#ifndef KC9ZDA_NCP5623_H
#define KC9ZDA_NCP5623_H

#define NCP5623_DEFAULT_ADDR 0x38

#define NCP5623_REG_ILED 1
#define NCP5623_REG_CHANNEL_BASE 2

class NCP5623
{
    public:
        /**
         * Constructor
         */
        NCP5623();

        /**
         * Initializes state of NCP5623
         */
        void begin();

        /**
         * Sets all color channels. Values 0-255
         * 
         * @param red       Red channel
         * @param green     Green channel
         * @param blue      Blue channel
         */
        void setColor(uint8_t red, uint8_t green, uint8_t blue);

        /**
         * Sets ILED (max current per channel). Rounds to nearest step
         * 
         * @param iled      Max current in milliamps (mA). 
         */
        void setCurrent(uint8_t iled);

        /**
         * Sets the value of a specific PWM channel
         * 
         * @param channel   PWM channel 0, 1, or 2
         * @param value     PWM value 0-31
         */
        void setChannel(uint8_t channel, uint8_t value);

        /**
         * Sets the intensity of the red channel
         * 
         * @param value     Intensity 0-255
         */
        void setRed(uint8_t value);

        /**
         * Sets the intensity of the green channel
         * 
         * @param value     Intensity 0-255
         */
        void setGreen(uint8_t value);

        /**
         * Sets the intensity of the blue channel
         * 
         * @param value     Intensity 0-255
         */
        void setBlue(uint8_t value);

        /**
         * Writes to a register
         * 
         * @param reg       Register 0-7
         * @param value     Value 0-31
         */
        void writeReg(uint8_t reg, uint8_t value);

        /**
         * Maps colors to channels
         * 
         * @param red       Channel 0-2
         * @param green     Channel 0-2
         * @param blue      Channel 0-2
         */
        void mapColors(uint8_t red, uint8_t green, uint8_t blue);

    private:
        /**
         * I2C address (usually hardcoded, but who knows what's out there)
         */
        uint8_t _addr;

        /**
         * Channel map. Specifies which channels on the chip go to R, G, or B.
         */
        uint8_t _red;
        uint8_t _green;
        uint8_t _blue;
};

#endif