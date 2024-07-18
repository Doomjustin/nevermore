#include <Catch2/catch_test_macros.hpp>

#include <string>
#include <array>

struct ArabicToRomanMapping{
    unsigned arabic_number;
    std::string roman_numeral;
};

std::string convert_arabic_to_roman_numeral(unsigned arabic_number)
{
    static std::array<ArabicToRomanMapping, 13> arabic_to_roman_mappings =
                {
                    ArabicToRomanMapping{ 1000, "M" },
                    { 900, "CM" },
                    { 500, "D" },
                    { 400, "CD" },
                    { 100, "C" },
                    { 90, "XC" },
                    { 50, "L" },
                    { 40, "XL" },
                    { 10, "X" },
                    { 9, "IX" },
                    { 5, "V" },
                    { 4, "IV" },
                    { 1, "I" }
                };

    std::string roman_numeral{};

    for (const auto& [arabic_number_unit, roman_numeral_digit]: arabic_to_roman_mappings) {
        while (arabic_number >= arabic_number_unit) {
            roman_numeral += roman_numeral_digit;
            arabic_number -= arabic_number_unit;
        }
    }

    return roman_numeral;
}

TEST_CASE("Arabic to Roman numerics converter test", "[converter]")
{
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
