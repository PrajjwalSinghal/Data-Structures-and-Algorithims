#project(lab04)

set(HEADER_FILES
        inc/linked_list.h
        inc/node.h
        )

set(SOURCE_FILES
        src/linked_list.cpp
        src/node.cpp
        )
include_directories(inc)
add_library(lab4_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

#target_include_directories(lab4_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

