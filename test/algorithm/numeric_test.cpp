#include <Catch2/catch_test_macros.hpp>

#include "nevermore/Numeric.h"

TEST_CASE("test factorial", "[numeric]")
{
    SECTION("test non-recursive implementation")
    {
        REQUIRE(1 == sf::factorial(0));
        REQUIRE(1 == sf::factorial(1));
        REQUIRE((2 * 1) == sf::factorial(2));
        REQUIRE((3 * 2 * 1) == sf::factorial(3));
        REQUIRE((10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) == sf::factorial(10));
    }

    SECTION("test recursive implementation")
    {
        REQUIRE(1 == sf::recursive::factorial(0));
        REQUIRE(1 == sf::recursive::factorial(1));
        REQUIRE((2 * 1) == sf::recursive::factorial(2));
        REQUIRE((3 * 2 * 1) == sf::recursive::factorial(3));
        REQUIRE((10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) == sf::recursive::factorial(10));
    }
}
