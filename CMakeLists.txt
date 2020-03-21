cmake_minimum_required(VERSION 3.0)

project(Booksa)
set (CMAKE_CXX_STANDARD 17)
message(">>>Component: ${PROJECT_NAME}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/domain)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/application)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/presentation)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/persistence)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/main)
