cmake_minimum_required(VERSION 3.5)

project(hello_web_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall")

# daqi project dir:
set(_DAQI_PROJECT_PATH_ "../../../../daqi/")
# daqi binary library (etc : libda4qi4.so libda4qi4.a ) dir:
set(_DAQI_LIBRARY_PATH_ "../../../../build/")

include_directories(${_DAQI_PROJECT_PATH_})
include_directories(${_DAQI_PROJECT_PATH_}/include)
include_directories(${_DAQI_PROJECT_PATH_}/nlohmann_json/include/)

find_package(Boost 1.65.0 REQUIRED COMPONENTS filesystem system)
link_directories(${_DAQI_LIBRARY_PATH_})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    link_libraries(da4qi4_d)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    link_libraries(da4qi4)
endif()

link_libraries(pthread)
link_libraries(ssl)
link_libraries(crypto)
link_libraries(boost_filesystem)
link_libraries(boost_system)

add_executable(_01_hello_world _01_main.cpp)
add_executable(_01_hello_world_lambda _01_main_lambda.cpp)
add_executable(_02_hello_html _02_main_html.cpp)
add_executable(_02_hello_html_template _02_main_html_template.cpp)
add_executable(_03_enable_detect_templates _03_main_enable_detect_template.cpp)
add_executable(_03_add _03_main_add.cpp)
