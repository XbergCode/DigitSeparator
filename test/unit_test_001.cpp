//
//    FILE: unit_test_001.cpp
//  AUTHOR: XbergCode
//    DATE: 13/08/2022
// PURPOSE: unit tests for the DigitSeparator library
//          https://github.com/XbergCode/DigitSeparator
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)


#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "DigitSeparator.h"



unittest_setup()
{
  fprintf(stderr, "DigitSeparator_VERSION: %s\n", (char *) DigitSeparator_VERSION);
}


unittest_teardown()
{
}


unittest(digitSeparate)
{
  fprintf(stderr, "\n digitSeparate Explain.\n");
  fprintf(stderr, "\n Signed Min Value       : \n");
  fprintf(stderr, "%s\n", digitSeparate(-9223372036854775807, '.') );
  fprintf(stderr, "\n Signed Max Value       : \n");
  fprintf(stderr, "%s\n", digitSeparate(9223372036854775807, '.') );
  fprintf(stderr, "\n");
  
  assertEqual(0, strcmp("-1.000",         digitSeparate(-1000, '.') ) );
  assertEqual(0, strcmp("10.000",         digitSeparate(10000, '.') ) );
  assertEqual(0, strcmp("-100.000",       digitSeparate(-100000, '.') ) );
}


unittest(digitSeparateU)
{
  fprintf(stderr, "\n digitSeparateU Explain.\n");
  fprintf(stderr, "\n Unsigned Min Value       : \n");
  fprintf(stderr, "%s\n", digitSeparateU(1, '.') );
  fprintf(stderr, "\n Unsigned Max Value       : \n");
  fprintf(stderr, "%s\n", digitSeparateU(18446744073709551615, '.') );
  fprintf(stderr, "\n");
  
  assertEqual(0, strcmp("1.000",          digitSeparateU(1000, '.') ) );
  assertEqual(0, strcmp("10.000",         digitSeparateU(10000, '.') ) );
  assertEqual(0, strcmp("100.000",        digitSeparateU(100000, '.') ) );
}


unittest(digitSeparateD)
{
  fprintf(stderr, "\n digitSeparateD Explain.\n");
  fprintf(stderr, "\n Double / Float Value   : \n");
  fprintf(stderr, "%s\n", digitSeparateD(1234567.123456, 0, '.', ',') );
  fprintf(stderr, "\n Double / Float Value   : \n");
  fprintf(stderr, "%s\n", digitSeparateD(1234567.123456, 6, '.', ',') );
  fprintf(stderr, "\n");
  
  assertEqual(0, strcmp("1.234.567",        digitSeparateD(1234567.123456, 0, '.', ',') ) );
  assertEqual(0, strcmp("1.234.567,123456", digitSeparateD(1234567.123456, 6, '.', ',') ) );
  //assertEqualFloat(1.234.567, digitSeparateD(1234567.123456, 0, '.', ','), 0.1);
  //assertEqualFloat(1.234.567,123456, digitSeparateD(1234567.123456, 0, '.', ','), 0.1);
}



unittest_main()

// --------
