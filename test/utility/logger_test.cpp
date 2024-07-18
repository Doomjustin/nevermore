#include <Catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include "nevermore/Logger.h"

#include <sstream>
#include <iostream>

TEST_CASE("log formatter test", "[LogFormatter]")
{
    auto now = sf::LogEntry::Clock::now();
    auto current_location = std::source_location::current();
    sf::LogEntry entry {
        .level = sf::LogLevel::Warning,
        .logger_name = "Log Formatter Test",
        .location = current_location,
        .occurred = now,
        .message = "This is a Message"
    };

    using Catch::Matchers::Equals;

    SECTION("won't format without prompt(%)")
    {
        sf::LogFormatter formatter{ "[m]" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals("[m]"));
    }

    SECTION("format message")
    {
        sf::LogFormatter formatter{ "[%m]" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals("[This is a Message]"));
    }

    SECTION("format line")
    {
        sf::LogFormatter formatter{ "%l" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals(std::to_string(current_location.line())));
    }

    SECTION("format column")
    {
        sf::LogFormatter formatter{ "%c" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals(std::to_string(current_location.column())));
    }

    SECTION("format function name")
    {
        sf::LogFormatter formatter{ "%F" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals(current_location.function_name()));
    }

    SECTION("format file name")
    {
        sf::LogFormatter formatter{ "%f" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals(current_location.file_name()));
    }

    SECTION("format time")
    {
        sf::LogFormatter formatter{ "%t" };
        auto formatted_str = formatter.format(entry);
        std::stringstream ss{};
        ss << now;
        REQUIRE_THAT(formatted_str, Equals(ss.str()));
    }

    SECTION("format logger name")
    {
        sf::LogFormatter formatter{ "%n" };
        auto formatted_str = formatter.format(entry);
        REQUIRE_THAT(formatted_str, Equals("Log Formatter Test"));
    }

    SECTION("format thread id")
    {
        sf::LogFormatter formatter{ "%T" };
        auto formatted_str = formatter.format(entry);
        std::stringstream ss{};
        ss << std::this_thread::get_id();
        REQUIRE_THAT(formatted_str, Equals(ss.str()));
    }
}


TEST_CASE("stdout logger test", "[logger]")
{
    std::stringstream buffer{};
    std::cout.rdbuf(buffer.rdbuf());

    sf::Logger logger{ "test logger" };

    auto stdout_log_appender = std::make_shared<sf::StdoutLogAppender>();
    logger.add_appender(std::move(stdout_log_appender));

    using Catch::Matchers::ContainsSubstring;
    using Catch::Matchers::Equals;

    SECTION("redirect succeed")
    {
        std::cout << "test message\n";

        REQUIRE_THAT(buffer.str(), Equals("test message\n"));
    }

    SECTION("output as format: [level] occurred_time: message")
    {
        logger.error("error message");
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("error message"));
    }

    SECTION("when logger's LogLevel is Off, won't log anything")
    {
        logger.level(sf::LogLevel::Off);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE(buffer.str().empty());
    }

    SECTION("when logger's LogLevel is Fatal, won't log message if level < Fatal")
    {
        logger.level(sf::LogLevel::Fatal);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE_THAT(buffer.str(), ContainsSubstring("[fatal]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("fatal message"));

        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[warning]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[info]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[debug]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[trace]"));
    }

    SECTION("when logger's LogLevel is Error, won't log message if level < Error")
    {
        logger.level(sf::LogLevel::Error);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE_THAT(buffer.str(), ContainsSubstring("[fatal]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("fatal message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("error message"));

        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[warning]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[info]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[debug]"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[trace]"));
    }

    SECTION("when logger's LogLevel is Trace, log all level's message")
    {
        logger.level(sf::LogLevel::Trace);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE_THAT(buffer.str(), ContainsSubstring("[fatal]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("fatal message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("error message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[warning]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("warning message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[info]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("info message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[debug]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("debug message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[trace]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("trace message"));
    }

    SECTION("when global LogLevel is Off, won't log anything")
    {
        sf::global_log_level(sf::LogLevel::Off);
        logger.level(sf::LogLevel::Trace);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE(buffer.str().empty());
    }

    SECTION("when global LogLevel is Debug, won't log message if level < Debug")
    {
        sf::global_log_level(sf::LogLevel::Debug);
        logger.level(sf::LogLevel::Trace);

        logger.fatal("fatal message");
        logger.error("error message");
        logger.warning("warning message");
        logger.info("info message");
        logger.debug("debug message");
        logger.trace("trace message");

        REQUIRE_THAT(buffer.str(), ContainsSubstring("[fatal]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("fatal message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[error]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("error message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[warning]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("warning message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[info]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("info message"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("[debug]"));
        REQUIRE_THAT(buffer.str(), ContainsSubstring("debug message"));
        REQUIRE_THAT(buffer.str(), !ContainsSubstring("[trace]"));
    }
}
