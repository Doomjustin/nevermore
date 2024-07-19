add_library(nevermore_utility STATIC
    include/nevermore/Converter.h
    include/nevermore/Noncopyable.h
    arabic_to_roman_numeric.cpp
)

add_library(nevermore::utility ALIAS nevermore_utility)
target_include_directories(nevermore_utility PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
