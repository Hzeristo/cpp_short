cmake_minimum_required(VERSION 3.21.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/6.9.1/gcc_64/lib/cmake/Qt6/")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

file(GLOB COMPONENT_HEADERS
    ${CMAKE_SOURCE_DIR}/src/include/*.h
    
)

file(GLOB COMPONENT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/game/*.cpp
)

add_executable(test
    src/main.cpp
    ${COMPONENT_HEADERS}    # 显式加入头文件
    ${COMPONENT_SOURCES}
)

target_link_libraries(test PRIVATE Qt6::Widgets)

message(STATUS "Include dirs: ${CMAKE_INCLUDE_PATH}")
