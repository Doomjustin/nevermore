#ifndef NEVERMORE_BASE_LOGGER_H
#define NEVERMORE_BASE_LOGGER_H

#include "nevermore/Logger.h"
#include "nevermore/LogFormatter.h"
#include "nevermore/LogAppender.h"
#include "nevermore/LogLevel.h"
#include "nevermore/LogEntry.h"

#include <string>
#include <source_location>
#include <vector>
#include <memory>

namespace sf {

class BaseLogger: public Logger {
public:
    explicit BaseLogger(std::string name);

    ~BaseLogger() override = default;

    void error(std::string message, std::source_location location) override;

    void warning(std::string message, std::source_location location) override;

    void info(std::string message, std::source_location location) override;

    void debug(std::string message, std::source_location location) override;

    void trace(std::string message, std::source_location location) override;

    void level(LogLevel new_level) noexcept override;

    LogLevel level() const noexcept override { return level_; }

    void add_appender(std::shared_ptr<LogAppender> appender);

    void pattern(std::string new_pattern) noexcept override;

private:
    std::string name_ = "NevermoreLogger";
    LogLevel level_ = LogLevel::Debug;
    LogFormatter formatter_ = LogFormatter{};
    std::vector<std::shared_ptr<LogAppender>> appenders_;

    void write(std::string message, LogLevel level, std::source_location location);

    void write(const LogEntry& entry);
};

} // namespace sf

#endif // NEVERMORE_BASE_LOGGER_H
