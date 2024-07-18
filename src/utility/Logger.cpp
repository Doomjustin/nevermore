#include "nevermore/Logger.h"

namespace sf {

Logger::Logger(std::string name)
  : name_{ std::move(name) }
{}

void Logger::fatal(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Fatal,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

void Logger::error(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Error,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

void Logger::warning(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Warning,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

void Logger::info(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Info,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

void Logger::debug(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Debug,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

void Logger::trace(std::string message, std::source_location location)
{
    LogEntry entry {
        .level = LogLevel::Trace,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

} // namespace sf
