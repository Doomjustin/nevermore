add_library(NEVERMORE_LOG STATIC
    include/nevermore/BaseLogger.h
    include/nevermore/LogAppender.h
    include/nevermore/LogEntry.h
    include/nevermore/LogFormatter.h
    include/nevermore/Logger.h
    include/nevermore/LogLevel.h
    include/nevermore/StdoutAppender.h
    include/nevermore/SpdLogger.h
    LogFormatter.cpp
    BaseLogger.cpp
    StdoutAppender.cpp
    SpdLogger.cpp
)

add_library(nevermore::log ALIAS NEVERMORE_LOG)

target_include_directories(NEVERMORE_LOG PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(NEVERMORE_LOG PUBLIC
    nevermore::utility
    spdlog::spdlog
)
