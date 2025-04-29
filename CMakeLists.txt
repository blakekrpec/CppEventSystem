cmake_minimum_required(VERSION 3.15)
project(CppEventSystem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# if(CMAKE_COMPILER_IS_GNUCXX)
#     set(CMAKE_CXX_STANDARD_LIBRARIES "-lc++")
# endif()

include_directories(include)

add_executable(CppEventSystem
    src/main.cpp
)

