#include "nevermore/LogFormatter.h"

#include <utility>
#include <ostream>

namespace sf {

std::ostream& operator<<(std::ostream& os, LogLevel level)
{
    switch (level) {
        using enum LogLevel;
    case Fatal:
        os << "fatal";
        break;
    case Error:
        os << "error";
        break;
    case Warning:
        os << "warning";
        break;
    case Info:
        os << "info";
        break;
    case Debug:
        os << "debug";
        break;
    case Trace:
        os << "trace";
        break;
    default:
        break;
    }

    return os;
}

void LogFormatter::MessageItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.message;
}

void LogFormatter::LineItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.location.line();
}

void LogFormatter::ColumnItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.location.column();
}

void LogFormatter::LogLevelItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.level;
}

void LogFormatter::TimeItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.occurred;
}

void LogFormatter::LoggerNameItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.logger_name;
}

void LogFormatter::ThreadIdItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.thread_id;
}

void LogFormatter::FunctionNameItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.location.function_name();
}

void LogFormatter::FileNameItem::parse(std::ostream& os, const LogEntry& entry)
{
    os << entry.location.file_name();
}


static constexpr char PROMPT = '%';

LogFormatter::LogFormatter(std::string pattern)
  : pattern_{ std::move(pattern) }
{
    items_['m'] = std::make_unique<MessageItem>();
    items_['l'] = std::make_unique<LineItem>();
    items_['c'] = std::make_unique<ColumnItem>();
    items_['L'] = std::make_unique<LogLevelItem>();
    items_['t'] = std::make_unique<TimeItem>();
    items_['n'] = std::make_unique<LoggerNameItem>();
    items_['T'] = std::make_unique<ThreadIdItem>();
    items_['f'] = std::make_unique<FileNameItem>();
    items_['F'] = std::make_unique<FunctionNameItem>();
}

std::string LogFormatter::format(const LogEntry& entry)
{
    std::stringstream buffer{};
    for (int i = 0; i < pattern_.size(); ++i) {
        if (pattern_[i] == PROMPT)
            items_.at(pattern_[++i])->parse(buffer, entry);
        else
            buffer << pattern_[i];
    }

    return buffer.str();
}

void LogFormatter::pattern(std::string new_pattern) noexcept
{
    pattern_ = std::move(new_pattern);
}

} // namespace sf
