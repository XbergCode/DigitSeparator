[![Arduino CI](https://github.com/XbergCode/DigitSeparator/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/XbergCode/DigitSeparator/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/XbergCode/DigitSeparator/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/XbergCode/DigitSeparator/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/XbergCode/DigitSeparator/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/github/license/XbergCode/DigitSeparator)](https://github.com/XbergCode/DigitSeparator/blob/master/LICENSE)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/XbergCode/DigitSeparator)](https://github.com/XbergCode/DigitSeparator/releases)
![code size:](https://img.shields.io/github/languages/code-size/XbergCode/DigitSeparator)


# DigitSeparator
Arduino library to separate digit value with marks and returns it as C string.


## Description

The DigitSeparator library contains functions that prints integers and decimals with separation marks.

Example:

If some int value is:            -1000000 it will output    -> -1.000.000

If some uint value is:           1000000 it will output     ->  1.000.000

If some double / float value is: 1000000.123 it will output ->  1.000.000,123 "Depends on how many decimals you want to output."

And so on.. 

digitSeparate();  works with: int64_t , int32_t / uint32_t , int16_t / uint16_t values.

digitSeparateU(); works with: uint64_t , uint32_t , uint16_t values.

digitSeparateD(); works with: double & float values.


## Interface

The following functions are implemented:

char * digitSeparate(int64 Integer, char ThousandSeparator);

char * digitSeparateU(uint64 Integer, char ThousandSeparator);

char * digitSeparateD(const double IN, const uint8_t Dec, char ThousandSeparator, char DecimalSeparator);


## Operation

See examples.


## Performance

Performance is hard to optimize. Most time is spend in splitting individual digits (div / mod 10).
