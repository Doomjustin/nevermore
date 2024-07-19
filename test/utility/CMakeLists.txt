macro(add_utility_test target)
    target_link_libraries(${target} PRIVATE
        Catch2::Catch2WithMain
        nevermore::utility
    )

    catch_discover_tests(${target})
endmacro()

add_executable(arabic_to_roman_numeric_converter_test arabic_to_roman_numeric_converter_test.cpp)
add_utility_test(arabic_to_roman_numeric_converter_test)
