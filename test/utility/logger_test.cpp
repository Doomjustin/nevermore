#include <Catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "nevermore/Logger.h"

#include <sstream>
#include <iostream>

TEST_CASE("stdout logger test", "[logger]")
{
    std::stringstream buffer{};
    std::cout.rdbuf(buffer.rdbuf());

    auto logger = std::make_shared<sf::StdoutLogger>("TestLogger");
    using Catch::Matchers::ContainsSubstring;
    using Catch::Matchers::Equals;

    SECTION("redirect succeed")
    {
        std::cout << "test message\n";

        REQUIRE_THAT(buffer.str(), Equals("test message\n"));
    }

    SECTION("output as format: [level] occurred_time: message")
    {
        logger->error("this is a info message");
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("this is a info message"));
    }
}
