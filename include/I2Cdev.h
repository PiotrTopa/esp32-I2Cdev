/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2015 Jeff Rowberg, Nicolas Baldeck

Rework:
- as cpp object
- allow use of more than one I2C port
- some minor protocol fixes and consistency
Copyright (c) 2022 Piotr Topa

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _I2CDEV_H_
#define _I2CDEV_H_

#include <driver/i2c.h>
#include "freertos/FreeRTOS.h"

#define I2C_NUM_DEFAULT I2C_NUM_0

class I2Cdev
{
public:
    I2Cdev(i2c_port_t i2cPortNumber = I2C_NUM_DEFAULT);
    void initialize(gpio_num_t sdaGpioNumber, gpio_num_t sclGpioNumber, uint32_t clockSpeed);
    void enable(bool isEnabled);

    int8_t readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data, uint16_t timeout = CONFIG_I2C_BUS_DEFAULT_READ_TIMEOUT);
    int8_t readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data, uint16_t timeout = CONFIG_I2C_BUS_DEFAULT_READ_TIMEOUT);
    int8_t readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data, uint16_t timeout = CONFIG_I2C_BUS_DEFAULT_READ_TIMEOUT);
    int8_t readWord(uint8_t devAddr, uint8_t regAddr, uint16_t *data, uint16_t timeout = CONFIG_I2C_BUS_DEFAULT_READ_TIMEOUT);
    int8_t readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data, uint16_t timeout = CONFIG_I2C_BUS_DEFAULT_READ_TIMEOUT);

    bool writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data);
    bool writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data);
    bool writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data);
    bool writeWord(uint8_t devAddr, uint8_t regAddr, uint16_t data);
    bool writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data);

private:
    i2c_port_t i2cNum;
    i2c_config_t conf;
};

#endif /* _I2CDEV_H_ */
