cmake_minimum_required(VERSION 3.5)

project(hello_web_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_web_server main.cpp)
