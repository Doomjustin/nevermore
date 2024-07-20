#ifndef NEVERMORE_LOG_LEVEL_H
#define NEVERMORE_LOG_LEVEL_H

#include <cstdint>

namespace sf {

enum class LogLevel: std::uint8_t {
    Off,
    Error,
    Warning,
    Info,
    Debug,
    Trace
};

} // namespace sf

#endif // NEVERMORE_LOG_LEVEL_H
