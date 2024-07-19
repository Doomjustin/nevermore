#include "nevermore/Logger.h"

namespace sf {

static LogLevel global_log_level_ = LogLevel::Trace;

void global_log_level(LogLevel new_level)
{
    global_log_level_ = new_level;
}

LogLevel global_log_level() noexcept
{
    return global_log_level_;
}

} // namespace sf
