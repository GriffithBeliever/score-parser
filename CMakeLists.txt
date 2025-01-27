cmake_minimum_required(VERSION 3.15)
project("Hello World")

# Include the include directory                                                                                                               
include_directories(include)

# Add the executable
add_executable(hello-world
  src/main.cpp
  src/library.cpp
)
