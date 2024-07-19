#ifndef NEVERMORE_LOGGER_H
#define NEVERMORE_LOGGER_H

#include "nevermore/Noncopyable.h"
#include "nevermore/LogLevel.h"
#include "nevermore/LogEntry.h"
#include "nevermore/LogAppender.h"
#include "nevermore/LogFormatter.h"

#include <string>
#include <source_location>
#include <memory>
#include <vector>

namespace sf {

void global_log_level(LogLevel new_level);

LogLevel global_log_level() noexcept;


class Logger: public Noncopyable {
public:
    explicit Logger(std::string name);

    ~Logger() override = default;

    void fatal(std::string message, std::source_location location = std::source_location::current());

    void error(std::string message, std::source_location location = std::source_location::current());

    void warning(std::string message, std::source_location location = std::source_location::current());

    void info(std::string message, std::source_location location = std::source_location::current());

    void debug(std::string message, std::source_location location = std::source_location::current());

    void trace(std::string message, std::source_location location = std::source_location::current());

    void level(LogLevel new_level) noexcept;

    constexpr LogLevel level() const noexcept { return level_; }

    void add_appender(std::shared_ptr<LogAppender> appender);

    void pattern(std::string new_pattern) noexcept;

private:
    std::string name_ = "NevermoreLogger";
    LogLevel level_ = LogLevel::Debug;
    LogFormatter formatter_ = LogFormatter{ "[%L] %t: %m" };
    std::vector<std::shared_ptr<LogAppender>> appenders_;

    void write(std::string message, LogLevel level, std::source_location location);

    void write(const LogEntry& entry);
};

} // namespace sf

#endif // NEVERMORE_LOGGER_H
