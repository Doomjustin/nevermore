#include <Catch2/catch_template_test_macros.hpp>

#include "nevermore/Numeric.h"

#include <cstdint>

using IntegralTypes = std::tuple<std::uint32_t,
                                 std::int32_t,
                                 std::uint64_t,
                                 std::int64_t>;

TEMPLATE_LIST_TEST_CASE("test factorial", "[numeric]", IntegralTypes)
{
    SECTION("test non-recursive implementation")
    {
        REQUIRE(1 == sf::factorial<TestType>(0));
        REQUIRE(1 == sf::factorial<TestType>(1));
        REQUIRE((2 * 1) == sf::factorial<TestType>(2));
        REQUIRE((3 * 2 * 1) == sf::factorial<TestType>(3));
        REQUIRE((10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) == sf::factorial<TestType>(10));
    }

    SECTION("test recursive implementation")
    {
        REQUIRE(1 == sf::recursive::factorial<TestType>(0));
        REQUIRE(1 == sf::recursive::factorial<TestType>(1));
        REQUIRE((2 * 1) == sf::recursive::factorial<TestType>(2));
        REQUIRE((3 * 2 * 1) == sf::recursive::factorial<TestType>(3));
        REQUIRE((10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1) == sf::recursive::factorial<TestType>(10));
    }
}


TEMPLATE_LIST_TEST_CASE("test fibonacci", "[numeric]", IntegralTypes)
{
    SECTION("test recursive implementation")
    {
        REQUIRE(sf::recursive::fibonacci<TestType>(0) == 0);
        REQUIRE(sf::recursive::fibonacci<TestType>(1) == 1);
        REQUIRE(sf::recursive::fibonacci<TestType>(2) == 1);
        REQUIRE(sf::recursive::fibonacci<TestType>(3) == 2);
        REQUIRE(sf::recursive::fibonacci<TestType>(4) == 3);
        REQUIRE(sf::recursive::fibonacci<TestType>(5) == 5);
        REQUIRE(sf::recursive::fibonacci<TestType>(6) == 8);
        REQUIRE(sf::recursive::fibonacci<TestType>(7) == 13);
        REQUIRE(sf::recursive::fibonacci<TestType>(8) == 21);
        REQUIRE(sf::recursive::fibonacci<TestType>(9) == 34);
        REQUIRE(sf::recursive::fibonacci<TestType>(10) == 55);
        REQUIRE(sf::recursive::fibonacci<TestType>(11) == 89);
        REQUIRE(sf::recursive::fibonacci<TestType>(12) == 144);
    }

    SECTION("test non-recursive implementation")
    {
        REQUIRE(sf::fibonacci<TestType>(0) == 0);
        REQUIRE(sf::fibonacci<TestType>(1) == 1);
        REQUIRE(sf::fibonacci<TestType>(2) == 1);
        REQUIRE(sf::fibonacci<TestType>(3) == 2);
        REQUIRE(sf::fibonacci<TestType>(4) == 3);
        REQUIRE(sf::fibonacci<TestType>(5) == 5);
        REQUIRE(sf::fibonacci<TestType>(6) == 8);
        REQUIRE(sf::fibonacci<TestType>(7) == 13);
        REQUIRE(sf::fibonacci<TestType>(8) == 21);
        REQUIRE(sf::fibonacci<TestType>(9) == 34);
        REQUIRE(sf::fibonacci<TestType>(10) == 55);
        REQUIRE(sf::fibonacci<TestType>(11) == 89);
        REQUIRE(sf::fibonacci<TestType>(12) == 144);
    }
}

TEMPLATE_LIST_TEST_CASE("test gcd", "[numeric]", IntegralTypes)
{
    REQUIRE(sf::recursive::gcd(0, 0) == 0);
    REQUIRE(sf::recursive::gcd(10, 0) == 10);
    REQUIRE(sf::recursive::gcd(0, 10) == 10);
    REQUIRE(sf::recursive::gcd(20, 30) == 10);
}
