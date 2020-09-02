# File description: cmake file for PM
# Created by: Hikari hashida
# Date created: 16/7/2019
# Date last modified: 16/7/2019
# Comment up to date?: NO

cmake_minimum_required(VERSION 3.9.1)
project(run_pm)

#support for C++14 or later
set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c")
#common source/header files contained in this directory

#set common source/header files
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)


# ----- EDIT HERE -----
# include all files that you need for this module 
# make sure to include src files ONE-BY-ONE.
add_executable(${PROJECT_NAME} 
    PMMain.cpp 
    ${COMMON}/SMObject.cpp)

#including common source/header files
target_include_directories(${PROJECT_NAME}  PRIVATE ${INCLUDE})
#linking common source/header files
target_link_directories(${PROJECT_NAME}     PRIVATE ${INCLUDE})
