# check for minimum requirements
cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

# set executables output binary to /bin directory of this project file.
# (${CMAKE_BINARY_DIR} is the default binary directory for "build" directory)
project(MTRN3500_Task)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/bin      #change this directory if desired
)

# ----- EDIT HERE -----
# Add module directories as needed.
# List from least dependent to most dependent

add_subdirectory(modules/module_A)
add_subdirectory(modules/module_B)
add_subdirectory(modules/DisplayModule)
add_subdirectory(modules/GPSModule)
add_subdirectory(modules/LaserModule)
add_subdirectory(modules/PMModule)
add_subdirectory(modules/VehicleModule)
add_subdirectory(modules/XboxModule)