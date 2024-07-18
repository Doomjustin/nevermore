#include "nevermore/Logger.h"

namespace sf {

Logger::Logger(std::string name)
  : name_{ std::move(name) }
{}

void Logger::fatal(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Fatal, location);
}

void Logger::error(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Error, location);
}

void Logger::warning(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Warning, location);
}

void Logger::info(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Info, location);
}

void Logger::debug(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Debug, location);
}

void Logger::trace(std::string message, std::source_location location)
{
    write(std::move(message), LogLevel::Trace, location);
}

void Logger::level(LogLevel new_level) noexcept
{
    level_ = new_level;
}

void Logger::write(std::string message, LogLevel level, std::source_location location)
{
    if (level > global_log_level() || level > level_)
        return;

    LogEntry entry {
        .level = level,
        .logger_name = name_,
        .location = location,
        .message = std::move(message)
    };

    write(std::move(entry));
}

static LogLevel global_log_level_ = LogLevel::Trace;

void global_log_level(LogLevel new_level)
{
    global_log_level_ = new_level;
}

LogLevel global_log_level() noexcept
{
    return global_log_level_;
}

} // namespace sf
