
//    FILE: DigitSeparator.cpp
//  AUTHOR: XbergCode
// VERSION: 0.1.1
// PURPOSE: Digit Separator library for Arduino. Separates digit value with marks and returns it as C string.
//     URL: https://github.com/XbergCode/DigitSeparator
//
// HISTORY
//  0.1.1  13/08/2022  Initial version

#include "DigitSeparator.h"                           // Include The Digit Separator Header

// Digit Separator
// Based on currency code made by Rob Tillaart.
char * digitSeparate(int64_t Integer, char ThousandSeparator) {   // Digit Separator - Signed & Unsigned
  static char OUT[32];                                                   // Out String
  uint8_t index = 0U;                                                    // String Place Counter
  uint8_t pos = 0U;                                                      // Separator Position Counter
  
  bool negative = Integer < 0;                                           // Check If The Value Is Negative
  if (negative) Integer = -Integer;
  
  // Make The String
  while (Integer > 0) {                                                  // Add The Integer To The String
    if ((pos > 0) && (pos % 3 == 0)) OUT[index++] = ThousandSeparator;   // Add The Thousand Separator To The String
    pos++;                                                               // Go To Next Position
    OUT[index++] = (Integer % 10) + '0';
    Integer /= 10;
  }
  if (negative) OUT[index++] = '-';                                      // Add The Negative Mark To The String
  OUT[index] = '\0';                                                     // Null Terminate The String

  // Reverse The String
  for (uint8_t i = 0, j = index - 1; i < index / 2; i++, j--) {          // Reverse The String
    char c = OUT[i];
    OUT[i] = OUT[j];
    OUT[j] = c;
  }
  return OUT;                                                            // Return The String
}
char * digitSeparateU(uint64_t Integer, char ThousandSeparator) { // Digit Separator - Unsigned
  static char OUT[32];                                                   // Out String
  uint8_t index = 0U;                                                    // String Place Counter
  uint8_t pos = 0U;                                                      // Separator Position Counter
  
  // Make The String
  while (Integer > 0) {                                                  // Add The Integer To The String
    if ((pos > 0) && (pos % 3 == 0)) OUT[index++] = ThousandSeparator;   // Add The Thousand Separator To The String
    pos++;                                                               // Go To Next Position
    OUT[index++] = (Integer % 10) + '0';
    Integer /= 10;
  }
  OUT[index] = '\0';                                                     // Null Terminate The String

  // Reverse The String
  for (uint8_t i = 0, j = index - 1; i < index / 2; i++, j--) {          // Reverse The String
    char c = OUT[i];
    OUT[i] = OUT[j];
    OUT[j] = c;
  }
  return OUT;                                                            // Return The String
}
char * digitSeparateD(const double IN, const uint8_t Dec, char ThousandSeparator, char DecimalSeparator) {  // Digit Separator - Double & Float
  int64_t Integer = IN;                                                  // Integer Holder "0,"
  uint32_t Decimal;                                                      // Decimal Holder ",0"
  // Find Out The Decimal
  if (Dec >= 1U) {                                                       // Find Out The Decimal Value
    uint32_t Decimals;                                                   // Decimal Multiplier
    if (Dec == 1U) Decimals = 10U;                                       // @ ,0
    else if (Dec == 2U) Decimals = 100U;                                 // @ ,00
    else if (Dec == 3U) Decimals = 1000U;                                // @ ,000
    else if (Dec == 4U) Decimals = 10000U;                               // @ ,0000
    else if (Dec == 5U) Decimals = 100000U;                              // @ ,00000
    else if (Dec == 6U) Decimals = 1000000U;                             // @ ,000000
    else Decimals = 10U;                                                 // Set To ,0
    Decimal = round ((IN - Integer) * Decimals);                         // Get The Decimal Value
    if ((IN - Integer) * Decimals >= 9U && Decimal == 10U) {             // Decimal Was Rounded From 9 To 0
      Integer = Integer + 1U;                                            // Add One To The Integer
      Decimal = 0U;                                                      // Decimal Is 0
    }
  }
  else {                                                                 // No Decimal Value, Check If It Needs Rounding
    Decimal = (IN - Integer) * 100U;                                     // Get The Decimal Value ,00
    if (Decimal >= 49U) Integer = Integer + 1U;                          // If We Are Over ,49 Then Add One To The Integer Value
  }
  
  static char OUT[32];                                                   // Out String
  uint8_t index = 0U;                                                    // String Place Counter
  uint8_t pos = 0U;                                                      // Separator Position Counter
  
  bool negative = Integer < 0;                                           // Check If The Value Is Negative
  if (negative) Integer = -Integer;
  
  // Make The String
  if (Dec >= 1U) {                                                       // Add The Decimal To The String
    while (pos < Dec) {
      pos++;                                                             // Go To Next Position
      OUT[index++] = (Decimal % 10) + '0';
      Decimal /= 10;
    }
    OUT[index++] = DecimalSeparator;                                     // Add The Decimal Separator To The String
  }
  pos = 0U;                                                              // Reset The Position
  while (Integer > 0) {                                                  // Add The Integer To The String
    if ((pos > 0) && (pos % 3 == 0)) OUT[index++] = ThousandSeparator;   // Add The Thousand Separator To The String
    pos++;                                                               // Go To Next Position
    OUT[index++] = (Integer % 10) + '0';
    Integer /= 10;
  }
  if (negative) OUT[index++] = '-';                                      // Add The Negative Mark To The String
  OUT[index] = '\0';                                                     // Null Terminate The String
  
  // Reverse The String
  for (uint8_t i = 0, j = index - 1; i < index / 2; i++, j--) {          // Reverse The String
    char c = OUT[i];
    OUT[i] = OUT[j];
    OUT[j] = c;
  }
  return OUT;                                                            // Return The String
}

// End Of File.
