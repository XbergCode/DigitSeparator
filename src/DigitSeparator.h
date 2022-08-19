#pragma once                                                          // Run Once

//    FILE: DigitSeparator.h
//  AUTHOR: XbergCode
// VERSION: 0.1.1
// PURPOSE: Digit Separator library for Arduino. Separates digit value with marks and returns it as C string.
//     URL: https://github.com/XbergCode/DigitSeparator


#define DigitSeparator_VERSION    (F("0.1.1\n"))                      // Verison 

#include <Arduino.h>                                                  // Include The Arduino Library

char * digitSeparate(int64_t, char);                                  // Digit Separator - Signed & Unsigned
char * digitSeparateU(uint64_t, char);                                // Digit Separator - Unsigned
char * digitSeparateD(const double, const uint8_t, char, char);       // Digit Separator - Double & Float

// End Of File.
