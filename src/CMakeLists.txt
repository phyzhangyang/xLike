file(GLOB SRC_FILES *.cpp)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
add_library(libxLike SHARED ${SRC_FILES})