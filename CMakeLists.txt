cmake_minimum_required(VERSION 3.26)

project(nevermore
    VERSION 0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(NoInSourceBuild)
include(AddModules)

add_subdirectory(src bin)
add_subdirectory(test)
