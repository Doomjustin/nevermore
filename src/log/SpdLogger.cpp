#include "nevermore/SpdLogger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace sf {

SpdLogger::SpdLogger(std::string name)
  : Logger{},
    logger_{ spdlog::stdout_color_mt(name) }
{
    logger_->set_pattern("%v");
}

void SpdLogger::error(std::string message, std::source_location location) noexcept
{
    logger_->error(format(std::move(message), location));
}

void SpdLogger::warning(std::string message, std::source_location location) noexcept
{
    logger_->warn(format(std::move(message), location));
}

void SpdLogger::debug(std::string message, std::source_location location) noexcept
{
    logger_->debug(format(std::move(message), location));
}

void SpdLogger::info(std::string message, std::source_location location) noexcept
{
    logger_->info(format(std::move(message), location));
}

void SpdLogger::trace(std::string message, std::source_location location) noexcept
{
    logger_->trace(format(std::move(message), location));
}

void SpdLogger::level(LogLevel level) noexcept
{
    switch (level) {
    case LogLevel::Off:
        logger_->set_level(spdlog::level::off);
        break;
    case LogLevel::Error:
        logger_->set_level(spdlog::level::err);
        break;
    case LogLevel::Warning:
        logger_->set_level(spdlog::level::warn);
        break;
    case LogLevel::Debug:
        logger_->set_level(spdlog::level::debug);
        break;
    case LogLevel::Info:
        logger_->set_level(spdlog::level::info);
        break;
    case LogLevel::Trace:
        logger_->set_level(spdlog::level::trace);
        break;
    }
}

LogLevel SpdLogger::level() const noexcept
{
    auto spdlog_level = logger_->level();
    switch (spdlog_level) {
    case spdlog::level::off:
        return LogLevel::Off;
    case spdlog::level::err:
        return LogLevel::Error;
    case spdlog::level::warn:
        return LogLevel::Warning;
    case spdlog::level::debug:
        return LogLevel::Debug;
    case spdlog::level::info:
        return LogLevel::Info;
    case spdlog::level::critical:
    case spdlog::level::n_levels:
    case spdlog::level::trace:
    default:
        return LogLevel::Trace;
    }
}

void SpdLogger::pattern(std::string new_pattern) noexcept
{
    formatter_.pattern(std::move(new_pattern));
}

std::string SpdLogger::format(std::string message, std::source_location location)
{
    LogEntry entry {
        .location = location,
        .message = std::move(message)
    };

    return formatter_.format(entry);
}

} // namespace sf
