//    FILE: DigitSeparator.ino
//  AUTHOR: XbergCode
// VERSION: 0.1.2
// PURPOSE: Digit Separator library for Arduino. Separates digit value with marks and returns it as C string.
//     URL: https://github.com/XbergCode/DigitSeparator

#include <DigitSeparator.h>                                      // Digit Separator Library

void setup() {
  // Start The Serial
  Serial.begin(115200UL);                                        // Start The Serial @ Baudrate
  delay(500UL);                                                  // Wait For Serial To Wake Up
  Serial.print(F("Digit Separator - Version: ")); Serial.println(DigitSeparator_VERSION);
  
  // Signed & Unsigned Value
  // digitSeparate - Min: -9223372036854775807 And Max: 9223372036854775807
  Serial.println(F("digitSeparate Explain."));                   // Serial Print
  Serial.print(F("Signed Min Value       : "));                  // Serial Print
  Serial.println(digitSeparate(-9223372036854775807LL, '.'));    // Value, Thousand Separator
  Serial.print(F("Signed Max Value       : "));                  // Serial Print
  Serial.println(digitSeparate(9223372036854775807LL, '.'));     // Value, Thousand Separator
  Serial.println();                                              // Serial Print New Line

  // Unsigned Value
  // digitSeparateU - Min: 0 And Max: 18446744073709551615
  Serial.println(F("digitSeparateU Explain."));                  // Serial Print
  Serial.print(F("Unsigned Min Value     : "));                  // Serial Print
  Serial.println(digitSeparateU(0U, '.'));                       // Value, Thousand Separator
  Serial.print(F("Unsigned Max Value     : "));                  // Serial Print
  Serial.println(digitSeparateU(18446744073709551615ULL, '.'));  // Value, Thousand Separator
  Serial.println();                                              // Serial Print New Line

  // Double & Float Value
  // digitSeparateD - Decimals: 0 To 6
  Serial.println(F("digitSeparateD Explain."));                  // Serial Print
  Serial.print(F("Double / Float Value   : "));                  // Serial Print
  Serial.println(digitSeparateD(1234567.123456, 0U, '.', ','));  // Value, Decimals, Thousand Separator, Decimal Separator
  Serial.print(F("Double / Float Value   : "));                  // Serial Print
  Serial.println(digitSeparateD(1234567.123456, 6U, '.', ','));  // Value, Decimals, Thousand Separator, Decimal Separator
  Serial.println();                                              // Serial Print New Line

  // Value To C String
  Serial.println(F("digitSeparate To C String Explain."));       // Serial Print
  char C_String[27U];                                            // String For The Value
  
  int64_t Int64_Value = -9223372036854775807LL;                  // Int64 Value
  strcpy(C_String, digitSeparate(Int64_Value, '.'));             // Value, Thousand Separator
  Serial.print(F("Int64 String           : "));                  // Serial Print
  Serial.println(C_String);                                      // Serial Print The String
  
  uint64_t Uint64_Value = 18446744073709551615ULL;               // Uint64 Value
  strcpy(C_String, digitSeparateU(Uint64_Value, '.'));           // Value, Thousand Separator
  Serial.print(F("Uint64 String          : "));                  // Serial Print
  Serial.println(C_String);                                      // Serial Print The String
  
  double Double_Value = 12345.123456;                            // Double Value
  strcpy(C_String, digitSeparateD(Double_Value, 6U, '.', ','));  // Value, Decimals, Thousand Separator, Decimal Separator
  Serial.print(F("Double / Float String  : "));                  // Serial Print
  Serial.println(C_String);                                      // Serial Print The String
  Serial.println();                                              // Serial Print New Line

  // Use With Default Separator Mark's
  Serial.println(F("Use Default Separator Marks Explain."));     // Serial Print
  Serial.print(F("Signed Value           : "));                  // Serial Print
  Serial.println(digitSeparate(-1234));                          // Value
  Serial.print(F("Unsigned Value         : "));                  // Serial Print
  Serial.println(digitSeparateU(1234U));                         // Value
  Serial.print(F("Double / Float Value   : "));                  // Serial Print
  Serial.println(digitSeparateD(-1234.1234F));                   // Value
  Serial.println();                                              // Serial Print New Line
  
  Serial.println(F("Done."));
  
  
  /* Serial Outputs:
     Digit Separator - Version: 0.1.2
     
     digitSeparate Explain.
     Signed Min Value       : -9.223.372.036.854.775.807
     Signed Max Value       : 9.223.372.036.854.775.807
      
     digitSeparateU Explain.
     Unsigned Min Value     : 0
     Unsigned Max Value     : 18.446.744.073.709.551.615
      
     digitSeparateD Explain.
     Double / Float Value   : 1.234.567
     Double / Float Value   : 1.234.567,125000
     
     digitSeparate To C String Explain.
     Int64 String           : -9.223.372.036.854.775.807
     Uint64 String          : 18.446.744.073.709.551.615
     Double / Float String  : 12.345,123047

     Use Default Separator Marks Explain.
     Signed Value           : -1.234
     Unsigned Value         : 1.234
     Double / Float Value   : -1.234,12
     
     Done.
  */
}

void loop() {
  
}

// End Of File.
