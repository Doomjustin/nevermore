#ifndef NEVERMORE_UTILITY_LOGGER_H
#define NEVERMORE_UTILITY_LOGGER_H

#include "Noncopyable.h"

#include <string_view>
#include <source_location>
#include <chrono>
#include <thread>
#include <cstdint>
#include <memory>
#include <vector>
#include <unordered_map>

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


class LogFormatter {
public:
    explicit LogFormatter(std::string pattern);

    std::string format(const LogEntry& entry);

    void pattern(std::string new_pattern) noexcept;

private:
    class Item: Noncopyable {
    public:
        ~Item() override = default;

        virtual void parse(std::ostream& os, const LogEntry& entry) = 0;
    };

    // %m
    class MessageItem: public Item {
    public:
        ~MessageItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %l
    class LineItem: public Item {
    public:
        ~LineItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %c
    class ColumnItem: public Item {
    public:
        ~ColumnItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %L
    class LogLevelItem: public Item {
    public:
        ~LogLevelItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %t
    class TimeItem: public Item {
    public:
        ~TimeItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %n
    class LoggerNameItem: public Item {
    public:
        ~LoggerNameItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %T
    class ThreadIdItem: public Item {
    public:
        ~ThreadIdItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %F
    class FunctionNameItem: public Item {
    public:
        ~FunctionNameItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

    // %f
    class FileNameItem: public Item {
    public:
        ~FileNameItem() override = default;

        void parse(std::ostream& os, const LogEntry& entry) override;
    };

private:
    std::string pattern_;
    std::unordered_map<char, std::unique_ptr<Item>> items_;
};


class LogAppender: public Noncopyable{
public:
    ~LogAppender() override = default;

    virtual void write(const std::string& message) = 0;
};


class StdoutLogAppender: public LogAppender {
public:
    ~StdoutLogAppender() override = default;

    void write(const std::string& message) override;
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

void global_log_level(LogLevel new_level);

LogLevel global_log_level() noexcept;

} // namespace sf

#endif // NEVERMORE_UTILITY_LOGGER_H
