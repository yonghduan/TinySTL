set(SRC test.cpp)

include_directories(../new_allocator)
include_directories(../)

add_executable(test ${SRC})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)