cmake_minimum_required(VERSION 3.0)

message(">>>>Folder: ${PROJECT_NAME}/Employee")

set(DOMAIN_EMPLOYEE_SOURCES "${CMAKE_CURRENT_LIST_DIR}/Employee.cpp")
set(DOMAIN_EMPLOYEE_SOURCES ${DOMAIN_EMPLOYEE_SOURCES} PARENT_SCOPE)
set(DOMAIN_EMPLOYEE_HEADERS "${CMAKE_CURRENT_LIST_DIR}/Employee.h")
set(DOMAIN_EMPLOYEE_HEADERS ${DOMAIN_EMPLOYEE_HEADERS} PARENT_SCOPE)
