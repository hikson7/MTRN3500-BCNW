#Description:    Root level cmake configuration file example.
#Created by:     Hikari Hashida
#Date created:   Sep 2020

# check for minimum requirements
cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(MTRN3500_Assignment)

# set executables output binary to /bin directory of this project file.
# (${CMAKE_BINARY_DIR} is the default binary directory for "build" directory)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/bin         #change this directory if desired
)

# ----- EDIT HERE -----
# Add module directories as needed.
# List from least dependent to most dependent
add_subdirectory(modules/module_A)
add_subdirectory(modules/module_B)
# add_subdirectory(modules/module_C) etc.
