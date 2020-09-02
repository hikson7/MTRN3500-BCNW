# File description: cmake file for Vehicle
# Created by: Hikari hashida
# Date created: 30/7/2019
# Date last modified: 30/7/2019
# Comment up to date?: NO

cmake_minimum_required(VERSION 3.9.1)
project(run_vehicle)

#support for C++14 or later
set(CMAKE_CXX_STANDARD 14)

set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

add_executable(${PROJECT_NAME} 
    VehicleMain.cpp 
    # Add more .cpp file here if you wish.
    # ... 
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
