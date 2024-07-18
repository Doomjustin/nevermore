#include <Catch2/catch_test_macros.hpp>

#include <string>

std::string convert_arabic_to_roman_numeral(int number)
{
    return "I";
}

TEST_CASE("Arabic to Roman numerics converter test", "[converter]")
{
    SECTION("1 -> I")
    {
        REQUIRE(convert_arabic_to_roman_numeral(1) == "I");
    }
}
