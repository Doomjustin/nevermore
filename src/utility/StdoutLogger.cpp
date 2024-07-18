#include "nevermore/Logger.h"

#include <utility>
#include <iostream>

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

StdoutLogger::StdoutLogger(std::string name)
  : Logger{ std::move(name) }
{}

void StdoutLogger::write(LogEntry entry)
{
    std::cout << '[' << entry.level
              << "] " << entry.occurred
              << " :" << entry.message
              << '\n';
}

} // namespace sf
