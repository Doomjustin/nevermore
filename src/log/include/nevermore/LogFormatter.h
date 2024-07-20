#ifndef NEVERMORE_LOG_FORMATTER_H
#define NEVERMORE_LOG_FORMATTER_H

#include "nevermore/Noncopyable.h"
#include "nevermore/LogEntry.h"

#include <string>
#include <unordered_map>

namespace sf {

class LogFormatter {
public:
    LogFormatter() = default;
    explicit LogFormatter(std::string pattern);

    std::string format(const LogEntry& entry);

    void pattern(std::string new_pattern) noexcept;

private:
    class Item: Noncopyable {
    public:
        ~Item() override = default;

        virtual void parse(std::ostream& os, const LogEntry& entry) = 0;
    };

    // members
    std::string pattern_ = "[%L] %t: %m";
    std::unordered_map<char, std::unique_ptr<Item>> items_;

    // Items

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

};

} // namespace sf

#endif // NEVERMORE_LOG_FORMATTER_H
