#ifndef NEVERMORE_SPDLOGGER_H
#define NEVERMORE_SPDLOGGER_H

#include "nevermore/Logger.h"
#include "nevermore/LogFormatter.h"

#include <spdlog/spdlog.h>

namespace sf {

class SpdLogger: public Logger {
public:
    explicit SpdLogger(std::string name);

    void error(std::string message, std::source_location location) noexcept override;

    void warning(std::string message, std::source_location location) noexcept override;

    void debug(std::string message, std::source_location location) noexcept override;

    void info(std::string message, std::source_location location) noexcept override;

    void trace(std::string message, std::source_location location) noexcept override;

    void level(LogLevel level) noexcept override;

    LogLevel level() const noexcept override;

    void pattern(std::string new_pattern) noexcept override;

private:
    LogFormatter formatter_ = LogFormatter{};
    std::shared_ptr<spdlog::logger> logger_;

    std::string format(std::string message, std::source_location location);
};

} // namespace sf

#endif // NEVERMORE_SPDLOGGER_H
