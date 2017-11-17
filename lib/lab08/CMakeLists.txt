#project(lab08)

set(HEADER_FILES
        inc/sorts.h)

set(SOURCE_FILES
        src/sorts.cpp)
include_directories(inc)
add_library(lab8_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(lab6_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

