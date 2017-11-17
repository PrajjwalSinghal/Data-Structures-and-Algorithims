#project(lab05)

set(HEADER_FILES
        inc/expression.h
        inc/node.h
        inc/stack.h
        inc/queue.h
        )

set(SOURCE_FILES
        src/expression.cpp
        src/node.cpp
        src/stack.cpp
        src/queue.cpp
        )
include_directories(inc)
add_library(lab5_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})

#target_include_directories(lab5_lib PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include")

