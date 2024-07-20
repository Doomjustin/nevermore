macro(add_log_test target)
    target_link_libraries(${target} PRIVATE
        Catch2::Catch2WithMain
        nevermore::log
    )

    catch_discover_tests(${target})
endmacro()

add_executable(base_logger_test base_logger_test.cpp)
add_log_test(base_logger_test)

add_executable(log_test log_test.cpp)
add_log_test(log_test)
