cmake_minimum_required(VERSION 3.17)
project(algorithm_practices)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(selection_sort sorting/selection_sort.cpp)

add_executable(insertion_sort sorting/insertion_sort.cpp)

add_executable(shellsort sorting/shellsort.cpp)

add_executable(knuth_shuffle sorting/knuth_shuffle.cpp)

add_executable(mergesort sorting/mergesort.cpp)

add_executable(quicksort sorting/quicksort.cpp)

add_executable(quickselect sorting/quickselect.cpp)
