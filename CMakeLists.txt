cmake_minimum_required(VERSION 3.21.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#set(CMAKE_PREFIX_PATH "/opt/Qt/6.9.1/gcc_64/lib/cmake/Qt6/")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(${CMAKE_SOURCE_DIR}/src/include)

file(GLOB_RECURSE MODEL_SRC ${CMAKE_SOURCE_DIR}/src/Model/*.cpp)
file(GLOB_RECURSE VIEW_SRC ${CMAKE_SOURCE_DIR}/src/View/*.cpp)
file(GLOB_RECURSE COMMON_SRC ${CMAKE_SOURCE_DIR}/src/Common/*.cpp)
file(GLOB_RECURSE ALL_HEADERS ${CMAKE_SOURCE_DIR}/src/include/*.h)

add_executable(${PROJECT_NAME}
    src/main.cpp
    ${MODEL_SRC}
    ${VIEW_SRC}
    ${COMMON_SRC}
    ${ALL_HEADERS}  # 可选
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test PRIVATE Qt6::Widgets)

message(STATUS "Include dirs: ${CMAKE_INCLUDE_PATH}")
