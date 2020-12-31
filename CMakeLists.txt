cmake_minimum_required(VERSION 3.17)
project(algorithm_practices)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output)
include_directories(include)
include_directories(sorting)
include_directories(data_structure)

file(GLOB libsort_source "sorting/*")
add_library(sort SHARED ${libsort_source} include/common.cpp)

add_executable(test_main test/test_main.cpp)
target_link_libraries(test_main sort)
