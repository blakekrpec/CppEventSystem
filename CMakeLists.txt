cmake_minimum_required(VERSION 3.15)
project(CppEventSystem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


option(COPY_CLANG_FORMAT "Copy .clang_format file to the project root" OFF)
if(COPY_CLANGD)
    configure_file(${CMAKE_SOURCE_DIR}/config/.clang-format ${CMAKE_SOURCE_DIR}/.clang-format COPYONLY)
endif()

option(COPY_CLANGD "Copy .clangd file to the project root" OFF)
if(COPY_CLANGD)
    configure_file(${CMAKE_SOURCE_DIR}/config/.clangd ${CMAKE_SOURCE_DIR}/.clangd COPYONLY)
endif()

include_directories(include)

add_executable(CppEventSystem
    src/main.cpp
    src/random01.cpp
)

