# File description: cmake file for display module
# Created by: Hikari hashida
# Date created: 17/7/2019
# Date last modified: 16/7/2019
# Comment up to date?: NO

cmake_minimum_required(VERSION 3.9.1)
project(run_display)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wno-deprecated-declarations")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)
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
    ${INCLUDE}
    ${DISPLAY_INC}
)

#make sure OpenGL/GLUT is installed
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE} ${DISPLAY_INC})
target_link_directories(${PROJECT_NAME} PRIVATE ${INCLUDE} ${DISPLAY_INC})