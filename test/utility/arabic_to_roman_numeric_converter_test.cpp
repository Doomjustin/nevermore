#include "catch2/catch_test_macros.hpp"
#include "nevermore/Converter.h"


TEST_CASE("Arabic to Roman numerics converter test", "[converter]")
{
    using namespace sf;

    REQUIRE(convert_arabic_to_roman_numeral(1) == "I");
    REQUIRE(convert_arabic_to_roman_numeral(2) == "II");
    REQUIRE(convert_arabic_to_roman_numeral(3) == "III");
    REQUIRE(convert_arabic_to_roman_numeral(4) == "IV");
    REQUIRE(convert_arabic_to_roman_numeral(5) == "V");
    REQUIRE(convert_arabic_to_roman_numeral(6) == "VI");
    REQUIRE(convert_arabic_to_roman_numeral(7) == "VII");
    REQUIRE(convert_arabic_to_roman_numeral(8) == "VIII");
    REQUIRE(convert_arabic_to_roman_numeral(9) == "IX");
    REQUIRE(convert_arabic_to_roman_numeral(10) == "X");
    REQUIRE(convert_arabic_to_roman_numeral(20) == "XX");
    REQUIRE(convert_arabic_to_roman_numeral(30) == "XXX");
    REQUIRE(convert_arabic_to_roman_numeral(33) == "XXXIII");
    REQUIRE(convert_arabic_to_roman_numeral(40) == "XL");
    REQUIRE(convert_arabic_to_roman_numeral(50) == "L");
    REQUIRE(convert_arabic_to_roman_numeral(90) == "XC");
    REQUIRE(convert_arabic_to_roman_numeral(100) == "C");
    REQUIRE(convert_arabic_to_roman_numeral(200) == "CC");
    REQUIRE(convert_arabic_to_roman_numeral(300) == "CCC");
    REQUIRE(convert_arabic_to_roman_numeral(333) == "CCCXXXIII");
    REQUIRE(convert_arabic_to_roman_numeral(400) == "CD");
    REQUIRE(convert_arabic_to_roman_numeral(500) == "D");
    REQUIRE(convert_arabic_to_roman_numeral(900) == "CM");
    REQUIRE(convert_arabic_to_roman_numeral(1000) == "M");
    REQUIRE(convert_arabic_to_roman_numeral(2000) == "MM");
    REQUIRE(convert_arabic_to_roman_numeral(2017) == "MMXVII");
    REQUIRE(convert_arabic_to_roman_numeral(3000) == "MMM");
    REQUIRE(convert_arabic_to_roman_numeral(3333) == "MMMCCCXXXIII");
    REQUIRE(convert_arabic_to_roman_numeral(3999) == "MMMCMXCIX");
}
