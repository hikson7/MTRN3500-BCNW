# File description: cmake file for xbox control
# Created by: Hikari hashida
# Date created: 21/7/2019
# Date last modified: 21/7/2019
# Comment up to date?: NO

cmake_minimum_required(VERSION 3.9.1)
project(run_xbox)

set(CMAKE_CXX_STANDARD 14)
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

add_executable(${PROJECT_NAME} 
    XboxMain.cpp 
    # Add more .cpp file here if you wish.
    # ... 
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
#make sure SDL2 is installed
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
