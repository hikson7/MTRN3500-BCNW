#Description:    Cmake configuration file for including OpenGL/Glut libraries and modules.
#Created by:     Hikari Hashida
#Date created:   Sep 2020
# 
# Assuming the sub-structure
# |--modules
# |   |--DisplayModule
# |       |--src_display
# |          |-- *.cpp
# |       |--include_display
# |          |-- *.hpp
# |       |--DisplayMain.cpp
# |  

cmake_minimum_required(VERSION 3.9.1)
set(CMAKE_CXX_STANDARD 14)

project(module_display)

# silence deprecated warning
set(GCC_COVERAGE_COMPILE_FLAGS "-Wno-deprecated-declarations")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")      

# common source/header file path.
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)
# local source/header file path.
set(DISPLAY src_display)
set(DISPLAY_INC include_display)

#adding executables *make sure to include src files one by one.
add_executable(${PROJECT_NAME}
    DisplayMain.cpp
    ${DISPLAY}/Camera.cpp
    ${DISPLAY}/Frustum.cpp
    ${DISPLAY}/Ground.cpp
    ${DISPLAY}/HUD.cpp
    ${DISPLAY}/KeyManager.cpp
    ${DISPLAY}/Messages.cpp
    ${DISPLAY}/MyVehicle.cpp
    ${DISPLAY}/Quaternion.cpp
    ${DISPLAY}/Shape.cpp
    ${DISPLAY}/VectorMaths.cpp
    ${DISPLAY}/Vehicle.cpp
)

#make sure OpenGL/GLUT is installed
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#linking requried libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARIES})
target_include_directories(${PROJECT_NAME}  PRIVATE ${INCLUDE} ${DISPLAY_INC})
target_link_directories(${PROJECT_NAME}     PRIVATE ${INCLUDE} ${DISPLAY_INC})