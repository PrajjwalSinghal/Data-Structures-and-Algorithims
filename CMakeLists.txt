cmake_minimum_required(VERSION 3.8)

project(cmpe126f17_labs)

add_definitions(-std=gnu++0x)

set(SOURCE_FILES main.cpp)
add_executable(labs_main ${SOURCE_FILES})

include_directories(lib/lab04/inc lib/lab06/inc lib/lab07/inc lib/lab08/inc)

add_subdirectory(lib/lab04 lab4_lib)
add_subdirectory(lib/lab05 lab5_lib)
add_subdirectory(lib/lab06 lab6_lib)
add_subdirectory(lib/lab07 lab7_lib)
add_subdirectory(lib/lab08 lab8_lib)


add_subdirectory(test)

target_link_libraries(labs_main lab4_lib lab5_lib lab6_lib lab7_lib lab8_lib)