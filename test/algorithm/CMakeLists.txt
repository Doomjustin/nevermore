macro(add_algorithm_test target)
    target_link_libraries(${target} PRIVATE
        Catch2::Catch2WithMain
        nevermore::algorithm
    )

    catch_discover_tests(${target})
endmacro()


add_executable(numeric_test numeric_test.cpp)
add_algorithm_test(numeric_test)
