cmake_minimum_required(VERSION 3.0)

message(">>>>Folder: ${PROJECT_NAME}/Common")
set(DOMAIN_COMMON_HEADERS "${CMAKE_CURRENT_LIST_DIR}/IEntity.h"
    "${CMAKE_CURRENT_LIST_DIR}/Address.h"
    "${CMAKE_CURRENT_LIST_DIR}/CustomContainers.h"
    "${CMAKE_CURRENT_LIST_DIR}/Name.h"
    "${CMAKE_CURRENT_LIST_DIR}/Price.h"
    "${CMAKE_CURRENT_LIST_DIR}/Phone.h"
    "${CMAKE_CURRENT_LIST_DIR}/Time.h")
set(DOMAIN_COMMON_HEADERS ${DOMAIN_COMMON_HEADERS} PARENT_SCOPE)
