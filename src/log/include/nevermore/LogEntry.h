#ifndef NEVERMORE_LOG_ENTRY_H
#define NEVERMORE_LOG_ENTRY_H

#include "LogLevel.h"

#include <chrono>
#include <string>
#include <source_location>
#include <thread>

namespace sf {

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

} // namespace sf

#endif // NEVERMORE_LOG_ENTRY_H
