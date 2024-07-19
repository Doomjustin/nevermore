#ifndef NEVERMORE_LOG_APPENDER_H
#define NEVERMORE_LOG_APPENDER_H

#include "nevermore/Noncopyable.h"

#include <string>

namespace sf {

class LogAppender: public Noncopyable{
public:
    ~LogAppender() override = default;

    virtual void write(const std::string& message) = 0;
};

} // namespace sf

#endif // NEVERMORE_LOG_APPENDER_H
