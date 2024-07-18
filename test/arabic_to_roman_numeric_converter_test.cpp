#include <Catch2/catch_test_macros.hpp>

#include <string>

std::string convert_arabic_to_roman_numeral(int number)
{
    std::string roman_numeral{};

    while (number >= 1) {
        roman_numeral += "I";
        number -= 1;
    }

    return roman_numeral;
}

TEST_CASE("Arabic to Roman numerics converter test", "[converter]")
{
    SECTION("1 -> I")
    {
        REQUIRE(convert_arabic_to_roman_numeral(1) == "I");
    }

    SECTION("2 -> II")
    {
        REQUIRE(convert_arabic_to_roman_numeral(2) == "II");
    }

    SECTION("3 -> III")
    {
        REQUIRE(convert_arabic_to_roman_numeral(3) == "III");
    }
}
