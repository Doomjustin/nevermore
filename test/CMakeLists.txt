list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

macro(add_catch2_test target)
    target_link_libraries(${target} PRIVATE Catch2::Catch2WithMain)
    catch_discover_tests(${target})
endmacro()

macro(sf_add_test target)
    target_link_libraries(${target} PRIVATE Catch2::Catch2WithMain)
    catch_discover_tests(${target})
endmacro()

add_executable(arabic_to_roman_numeric_converter_test arabic_to_roman_numeric_converter_test.cpp)
add_catch2_test(arabic_to_roman_numeric_converter_test)
