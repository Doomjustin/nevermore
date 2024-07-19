#ifndef NEVERMORE_STDOUT_APPENDER_H
#define NEVERMORE_STDOUT_APPENDER_H

#include "LogAppender.h"

namespace sf {

class StdoutAppender: public LogAppender {
public:
    ~StdoutAppender() override = default;

    void write(const std::string& message) override;
};

} // namespace sf

#endif // NEVERMORE_STDOUT_APPENDER_H
