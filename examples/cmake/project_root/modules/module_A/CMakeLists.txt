#Description:    Subdirectory level cmake configuration file example.
#Created by:     Hikari Hashida
#Date created:   Sep 2020

# Define cmake version here.
cmake_minimum_required(VERSION 3.14.5)
# Define C++ version here.
set(CMAKE_CXX_STANDARD 14)

# Define module name here.
project(module_A)

# set path variables for common source/header files
# you can create your own using set(VAR_NAME PATH) and use the variable with $(VAR_NAME)
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

# ----- EDIT HERE -----
# include all files that you need for this module 
# make sure to include src files ONE-BY-ONE.

add_executable(
    ${PROJECT_NAME} 
    mainA.cpp
    ${COMMON}/common_source_file1.cpp
    ${COMMON}/common_source_file2.cpp  
)

# set path containing necessary header files.
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
# linking files.
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})