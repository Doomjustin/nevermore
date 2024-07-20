add_library(NEVERMORE_ALGORITHM INTERFACE
    include/nevermore/Numeric.h
)

add_library(nevermore::algorithm ALIAS NEVERMORE_ALGORITHM)

target_include_directories(NEVERMORE_ALGORITHM INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(NEVERMORE_ALGORITHM INTERFACE fmt::fmt)
