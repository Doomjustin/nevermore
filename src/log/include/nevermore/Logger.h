#ifndef NEVERMORE_LOGGER_H
#define NEVERMORE_LOGGER_H

#include "nevermore/Noncopyable.h"
#include "nevermore/LogLevel.h"

#include <string>
#include <source_location>
#include <format>

namespace sf {

class Logger: public Noncopyable {
public:
    ~Logger() override = default;

    virtual void error(std::string message, std::source_location location) = 0;

    virtual void warning(std::string message, std::source_location location) = 0;

    virtual void info(std::string message, std::source_location location) = 0;

    virtual void debug(std::string message, std::source_location location) = 0;

    virtual void trace(std::string message, std::source_location location) = 0;

    virtual void level(LogLevel new_level) noexcept = 0;

    virtual LogLevel level() const noexcept = 0;

    virtual void pattern(std::string new_pattern) noexcept = 0;
};

} // namespace sf

#ifndef NDEBUG
#include <spdlog/spdlog.h>
    #define SF_ERROR SPDLOG_ERROR
    #define SF_WARN SPDLOG_wARN
    #define SF_DEBUG SPDLOG_DEBUG
    #define SF_INFO SPDLOG_INFO
    #define SF_TRACE SPDLOG_TRACE
#else
    #define SF_ERROR(...)
    #define SF_WARN(...)
    #define SF_DEBUG(...)
    #define SF_INFO(...)
    #define SF_TRACE(...)
#endif

#endif // NEVERMORE_LOGGER_H
