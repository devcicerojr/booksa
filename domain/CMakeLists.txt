cmake_minimum_required(VERSION 3.0)

project(Domain)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

message(">>>Component: ${PROJECT_NAME}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Asset")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Business")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/BusinessCalendar")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Common")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Customer")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Employee")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Order")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/WorkDay")

set(DOMAIN_SOURCES ${DOMAIN_COMMON_SOURCES})
set(DOMAIN_HEADERS ${DOMAIN_COMMON_HEADERS})

add_library(${PROJECT_NAME} ${DOMAIN_SOURCES} ${DOMAIN_HEADERS})
