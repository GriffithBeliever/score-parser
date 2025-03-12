cmake_minimum_required(VERSION 3.15)
project("Hello World")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include the include directory                                                                                                               
include_directories(include)

# Add the executable
add_executable(test-score
  src/main.cpp
  src/library.cpp
)
