#include "nevermore/BaseLogger.h"

namespace sf {

BaseLogger::BaseLogger(std::string name)
  : Logger{},
    name_{ std::move(name) }
{}

void BaseLogger::error(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Error, location);
}

void BaseLogger::warning(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Warning, location);
}

void BaseLogger::info(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Info, location);
}

void BaseLogger::debug(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Debug, location);
}

void BaseLogger::trace(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Trace, location);
}

void BaseLogger::level(LogLevel new_level) noexcept
{
    level_ = new_level;
}

void BaseLogger::add_appender(std::shared_ptr<LogAppender> appender)
{
    appenders_.push_back(std::move(appender));
}

void BaseLogger::write(std::string message, LogLevel level, std::source_location location)
{
    if (level > level_)
        return;

    LogEntry entry {
        .level = level,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(entry);
}

void BaseLogger::write(const LogEntry& entry)
{
    auto formatted_message = formatter_.format(entry);
    for (auto& appender: appenders_)
        appender->write(formatted_message);
}

void BaseLogger::pattern(std::string new_pattern) noexcept
{
    formatter_.pattern(std::move(new_pattern));
}

} // namespace sf
