cmake_minimum_required(VERSION 3.9)
project(xLike VERSION 0.0.1 LANGUAGES CXX)
enable_language(CXX)

# flags
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# includes
include_directories(
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

# add relevant dirs
add_subdirectory(src)
add_subdirectory(main)

