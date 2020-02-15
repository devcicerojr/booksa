cmake_minimum_required(VERSION 3.0)

project(Booksa)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)
message(">>>Component: ${PROJECT_NAME}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/main)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/application)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/domain)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/presentation)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/persistence)