add_executable(logger_test logger_test.cpp)

target_link_libraries(logger_test PRIVATE
    Catch2::Catch2WithMain
    nevermore::log
)

catch_discover_tests(logger_test)
