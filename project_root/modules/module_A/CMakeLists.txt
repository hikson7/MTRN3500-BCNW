cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(module_A)

# set path for common source/header files
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

# ----- EDIT HERE -----
# include all files that you need for this module 
# make sure to include src files ONE-BY-ONE.

add_executable(
    ${PROJECT_NAME} 
    mainA.cpp               # e.g. file1.cpp file2.cpp
    ${COMMON}/common1.cpp
    ${COMMON}/common2.cpp   # e.g. ${COMMON}/common3.cpp ...
)

# common header files
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
# linking common source/header files
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})