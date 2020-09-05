# cmake

```cmake``` is a totally awesome tool especially when making large projects in C/C++. 

It let's us abandon confusing Makefile syntaxes and instead use cmake configuration files called ```CMakeLists.txt```. 

## CMakeLists.txt
Under ```project_root/``` directory, you'd probably already seen a few. Normally for a simple project (let's say one module and one executable), it would require you to have one ```CMakeLists.txt```, which is a configuration file ```cmake``` uses to compile your code. 

For larger projects like this project, we will still need ```CMakeLists.txt``` for each module; as well as the top level ```CMakeLists.txt``` that let's you compile each module using a single ```make``` command.

### Top-level CMakeLists.txt

Top-level ```cmake``` configuration file is nothing but a placeholder that looks for module-level ```CMakeLists.txt```. You can also set the destination directory for your executables.

#### Set ```cmake``` version requirement
To make sure ```cmake``` version installed on the machine matches the minimum requirement version, you can do this by,
```
cmake_minimum_required(VERSION x.xx.x) # x.xx.x is your version number
```
#### Set ```C++``` standard
Similarly, you can set ```cmake``` to expect minimum ```C++``` standard by setting ```CMAKE_CXX_STANDARD``` variable.
```
set(CMAKE_CXX_STANDARD XX) # XX is the C++ standard e.g. 14
```
#### Set project name
You can define ```PROJECT_NAME``` which doesn't mean much for top-level configuration file. Nevertheless ```cmake``` doesn't like it when you don't have a project name so you need to define one,
```
project(module_A)
```
#### Set destination directory for executables

You can set ```${CMAKE_RUNTIME_OUTPUT_DIRECTORY}``` variable to decide where you want your executables to appear.
```
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/bin         #change this directory if desired
)
```
#### Include module-level directories
You can add directories to your module-level configuration files, so that ```cmake``` can find them. Do this simply by ```add_subdirectory(path-to-module)```.

Overall top-level configuration file would like something like this
```
cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(MTRN3500_Assignment)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/bin         #change this directory if desired
)

add_subdirectory(modules/module_A)
add_subdirectory(modules/module_B)
# add_subdirectory(modules/module_C) etc.
```

### Module-level CMakeLists.txt

Module-level configuration file exits inside each module directory, namely ```project_root/modules/module_name/CMakeLists.txt```. If you wish, it is possible to create a ```cmake``` project off this configuration file, so that you can run ```make``` to compile for just for the single module. 

Note: \
If you do this, ```${CMAKE_SOURCE_DIR}``` won't be ```project_root``` anymore but changes to ```module_name```. If you want it to be ```project_root``` again, simply delete all the ```cmake``` files (other than ```CMakeLists.txt```) in ```module_name``` and rebuild ```cmake``` project at ```project_root```.

The point is that module-level configuration file contains rules for compiling that particular module only; hence you need one for each module.

Typically such ```CMakeLists.txt``` looks like this,
``` 
cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(module_A)

set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)

add_executable(
    ${PROJECT_NAME} 
    mainA.cpp
    ${COMMON}/common_source_file1.cpp
    ${COMMON}/common_source_file2.cpp  
)

target_include_directories(${PROJECT_NAME}  PRIVATE ${INCLUDE})
target_link_directories(${PROJECT_NAME}     PRIVATE ${INCLUDE})
```

#### Set module name
Unlike top-level configuration file, ```PROJECT_NAME``` here can be used for the executable name for your module. You can set project name i.e. module name with,
```
project(module_A)
```
#### Create variables
You can create variables, typically to define a path to source/include files that you need to compile your module. Since we have common source/include files for the project e.g. ```SMObject.cpp .hpp```, we set ```${COMMON}``` and ```${INCLUDE}``` path variables.
```
set(COMMON ${CMAKE_SOURCE_DIR}/common_src)
set(INCLUDE ${CMAKE_SOURCE_DIR}/common_include)
```
Note that ```${CMAKE_SOURCE_DIR}``` is set as the directory where you run ```cmake -B build```. So if you built ```cmake``` project for this single module, ```${CMAKE_SOURCE_DIR}``` will be set as ```module_name``` rather than ```project_root```.

#### Add ```.cpp``` files

You can add source files you need for your project with ```add_executable()``` command. Note that you need to add the files one by one, just like when you run ```g++```.
```
add_executable(
    ${PROJECT_NAME} 
    mainA.cpp
    ${COMMON}/common_source_file1.cpp
    ${COMMON}/common_source_file2.cpp  
)
```
#### Add include directory and Linking 
Finally, you can tell the compiler where to look for your ```.hpp``` files with,
```
target_include_directories(${PROJECT_NAME}  PRIVATE ${INCLUDE})
```
and similarly for linking ```.hpp```,
```
target_link_directories(${PROJECT_NAME}     PRIVATE ${INCLUDE})
```
If you wish, you can also add a path to a directory containing libraries.
```
target_link_libraries(${PROJECT_NAME} ${YOUR_LIBRARY_PATH})
```

# Useful Resources

```cmake``` documentation: https://cmake.org/documentation/