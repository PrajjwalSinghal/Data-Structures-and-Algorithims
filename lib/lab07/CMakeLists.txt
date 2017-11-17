#project(lab07)

set(HEADER_FILES
        inc/node.h
        inc/tree.h
        )

set(SOURCE_FILES
        src/tree.cpp)
include_directories(inc)
add_library(lab7_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

#target_include_directories(lab7_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

