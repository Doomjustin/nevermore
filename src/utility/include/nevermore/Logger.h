#ifndef NEVERMORE_UTILITY_LOGGER_H
#define NEVERMORE_UTILITY_LOGGER_H

#include "Noncopyable.h"

#include <string_view>
#include <source_location>
#include <chrono>
#include <thread>
#include <cstdint>
#include <memory>

namespace sf {

enum class LogLevel: std::uint8_t {
    Off,
    Fatal,
    Error,
    Warning,
    Info,
    Debug,
    Trace
};

struct LogEntry {
    using Clock = std::chrono::system_clock;
    using TimePoint = typename Clock::time_point;

    LogLevel level;
    std::string logger_name;
    std::source_location location;
    TimePoint occurred = Clock::now();
    std::thread::id thread_id = std::this_thread::get_id();
    std::string message;
};

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

protected:
    std::string name_ = "NevermoreLogger";
    LogLevel level_ = LogLevel::Debug;

    virtual void write(LogEntry entry) = 0;

private:
    void write(std::string message, LogLevel level, std::source_location location);
};


class StdoutLogger: public Logger {
public:
    explicit StdoutLogger(std::string name);

    ~StdoutLogger() override = default;

    void write(LogEntry entry) override;
};

} // namespace sf

#endif // NEVERMORE_UTILITY_LOGGER_H
