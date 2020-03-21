cmake_minimum_required(VERSION 3.0)

project(Domain)

#TODO: Update Asset and Service classes
#TODO: Add Inline to functions applicable
#TODO: Service / Product discount logic


message(">>>Component: ${PROJECT_NAME}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Asset")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Business")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/BusinessCalendar")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Common")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Customer")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Employee")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/Order")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/WorkDay")

include_directories()

set(DOMAIN_SOURCES ${DOMAIN_COMMON_SOURCES}
    ${DOMAIN_CUSTOMER_SOURCES}
    ${DOMAIN_EMPLOYEE_SOURCES}
    ${DOMAIN_ASSET_SOURCES}
    ${DOMAIN_BUSINESS_CALENDAR_SOURCES}
    ${DOMAIN_WORKDAY_SOURCES}
    ${DOMAIN_BUSINESS_SOURCES})
set(DOMAIN_HEADERS ${DOMAIN_COMMON_HEADERS}
    ${DOMAIN_CUSTOMER_HEADERS}
    ${DOMAIN_EMPLOYEE_HEADERS}
    ${DOMAIN_ASSET_HEADERS}
    ${DOMAIN_BUSINESS_CALENDAR_HEADERS}
    ${DOMAIN_WORKDAY_HEADERS}
    ${DOMAIN_BUSINESS_HEADERS})


add_library(${PROJECT_NAME} ${DOMAIN_SOURCES} ${DOMAIN_HEADERS})
