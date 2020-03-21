cmake_minimum_required(VERSION 3.0)

project(Main)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

message(">>>Component: ${PROJECT_NAME}")
add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
