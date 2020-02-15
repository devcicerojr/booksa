cmake_minimum_required(VERSION 3.0)

project(Main)
message(">>>Component: ${PROJECT_NAME} main")
add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
