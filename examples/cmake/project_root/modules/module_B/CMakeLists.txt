#Description:    Subdirectory level cmake configuration file example.
#Created by:     Hikari Hashida
#Date created:   Sep 2020

cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(module_B)

set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

add_executable(
    ${PROJECT_NAME} 
    mainB.cpp 
    moduleB.h      
    ${COMMON}/common_source_file1.cpp 
    ${COMMON}/common_source_file2.cpp 
)

target_include_directories(${PROJECT_NAME}  PRIVATE ${INCLUDE})
target_link_directories(${PROJECT_NAME}     PRIVATE ${INCLUDE})