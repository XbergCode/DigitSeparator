#pragma once                                                          // Run Once

//    FILE: DigitSeparator.h
//  AUTHOR: XbergCode
// VERSION: 0.1.2
// PURPOSE: Digit Separator library for Arduino. Separates digit value with marks and returns it as C string.
//     URL: https://github.com/XbergCode/DigitSeparator


#define DigitSeparator_VERSION    (F("0.1.2\n"))                      // Verison 

#include <Arduino.h>                                                  // Include The Arduino Library

// Default Separator Mark's
const char defaultThousand = '.';                                     // Default Thousand Mark
const char defaultDecimal  = ',';                                     // Default Decimal Mark

// Digit Separator's
char * digitSeparate(int64_t, char tMARK = defaultThousand);          // Digit Separator - Signed & Unsigned
char * digitSeparateU(uint64_t, char tMARK = defaultThousand);        // Digit Separator - Unsigned
char * digitSeparateD(const double, const uint8_t Dec = 2U, char tMARK = defaultThousand, char dMARK = defaultDecimal); // Digit Separator - Double & Float

// End Of File.
