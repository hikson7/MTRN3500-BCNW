# File description: cmake file for Laser module
# Created by: Hikari hashida
# Date created: 16/7/2019
# Date last modified: 16/7/2019
# Comment up to date?: NO

cmake_minimum_required(VERSION 3.9.1)
project(run_laser)

#support for C++14 or later
set(CMAKE_CXX_STANDARD 14)

#set common source/header files
#common source/header files contained in this directory
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

add_executable(${PROJECT_NAME} 
    LaserMain.cpp 
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
#make sure ncurses installed
find_package(Curses REQUIRED)
include_directories( ${CURSES_INCLUDE_DIRS})

target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE} ${CURSES_LIBRARIES})