
# Guide to cmake

## What is it, why do we need it?

TLDR; ```cmake``` provides a higher level of abstraction to ```Makefile```, a build configuration file that will help us easily create and configure large projects.

### A quick revision on creating a program
You may recall from COMP1511, for your computer to understand your C code it needs to be converted into a machine code, as an executable file (it would have .exe (Windows) or nothing at the end of the file name). For a simple program (say ```my_simple_program.c```), it may look like this:

```
$ gcc my_simple_program.c -o my_executable_name
```

This will produce an executable called ```my_executable_name```, which can be run like this.

```
$ ./my_executable_name
```

Note: ```gcc``` is a command line tool (CLI) to combine (or more formally, compiling and linking) your code.

> CLI is a program that you run from your console/terminal. It doesn't have a graphical user interface (GUI) like a typical software - but they can be very very useful. In reality, software with GUI most likley uses CLI under the hood!

### Creating multiple programs

For a simple project like above, running ```gcc``` (or ```g++``` for C++ program) on your terminal is enough. But, what if you want to produce multiple executables? Since ```gcc```/```g++``` can only produce a single executable at a time, you may need to do the following. (Note: each of the .c file would contain its own main function).

```
$ gcc my_simple_program.c -o my_executable_1
$ gcc my_awesome_program1.c -o my_executable_2
$ gcc my_awesome_program2.c -o my_executable_3
```

That works, but its not very elegant - also once you start making frequent changes to the code, repeating above process become tedius very quickly. To mitigate this, you can simplify this process by creating a ```Makefile``` - it is a very powerful method to build complicated and large projects. Once you write your own ```Makefile```, you can build your projects by running ```make```. (Note: ```Makefile``` must be named this way - otherwise ```make``` won't be able to find it).
```
$ make
```

### Makefile vs cmake

```Makefile``` is what you need to build a large project. But I haven't shown what inside of ```Makefile``` actually looks like. I have few reasons for this:

- ```Makefile``` has its own syntaxing and formating that may not be very intuitative. Quickly ```Makefile``` can get difficult to write and understand, particularly for a large multi-process project.
- I didn't want to scare people away by looking into the ugly side of ```Makefile```.
- There is a better way!

Our friend here is ```cmake```. It is a tool that let's us use more "human friendly" language to produce the ```Makefile``` we need. In essense, you never have to look at a ```Makefile``` - ```cmake``` will produce that for us, and we can simply run ```make``` to build and produce executables.

## Installations
When you're ready, let's install ```cmake``` on your machine.
### With Homebrew
```
$ brew install cmake
```
> Don't have Homebrew installed? Homebrew is a CLI that let's you easily install/manage various other CLIs like cmake. Checkout https://zellwk.com/blog/homebrew/

### Normal installation
Visit https://cmake.org/install/ and follow the instructions.

To check if it is installed correctly, you can run ``` cmake --version ```.
```
$ cmake --version                                                                
cmake version 3.18.1
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
### Trouble shooting
* ```cmake``` is not found from the command line terminal.

This means your machine doesn't know where ```cmake``` executable is (rememeber, ```cmake``` is just another program). Usually, you can find those programs in ```/usr/local/bin``` directory. You want to add this to an environmental variable called ```PATH``` in ```~/.zshrc``` (or``` ~/.bashrc``` for OS older than Catalina, or Linux).

```
$ export PATH="/usr/local/bin:$PATH"
$ source ~/.zshrc       # or source ~/.bashrc
```
Now your terminal should find ```cmake``` as a command. Note that you need to run ```source ~/.zshrc``` to take effect for that terminal straight away. For every new terminal, it should work without re running above commands.

## Creating a ```cmake``` project

To create ```cmake``` project, go to ```project_root``` directory, then run ```cmake```.
```
$ cd project_root/
$ cmake -B build
```
This should create a build folder (if it didn't exist before), and add all necessary ```cmake``` configurations will be created.

## Building the project
To build all files and produce executables, run following at your root project directory:
```
# at project_root/
$ make -C build
```
Now you should see executables in ```project_root/bin``` folder. There should be an executable for each module.

To clean (i.e. start ```cmake``` project from scratch) ```cmake``` project, simply delete ```project_root/build```. This doesn't delete your files - but it forces ```cmake``` to re-create the project when you run ```cmake -B build```.

## CMakeLists.txt

Now let's talk about CMakeLists.txt. If you look inside ```project_root/```, you see a ```CMakeLists.txt```, and if you also look inside ```project_root/modules/module_*```, you see there is a ```CMakeLists.txt``` for each of the modules.

Let's do a break down of those files.
<!-- 
you'd probably already seen a few. Normally for a simple project (let's say one module and one executable), it would require you to have one ```CMakeLists.txt```, which is a configuration file ```cmake``` uses to compile your code. 

For larger projects like this project, we will still need ```CMakeLists.txt``` for each module; as well as the top level ```CMakeLists.txt``` that let's you compile each module using a single ```make``` command. -->

### Top-level CMakeLists.txt

This is the ```CMakeLists.txt``` in ```project_root/``` directory. This ```CMakeLists.txt``` does two things:

1. specify where the executable will be created.
2. add subdirectory to the project folder, so that it can find module-level ```CMakeLists.txt```

This file doesn't actually contain any "interesting" contents - all module-related build configurations are set in module-level ```CMakeLists.txt```

<details>
<summary> Detailed breakdown </summary>

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
    ${CMAKE_SOURCE_DIR}/bin     #change this directory if desired
)
```

### Include module-level directories
You can add directories to your module-level configuration files, so that ```cmake``` can find them. Do this simply by ```add_subdirectory(path-to-module)```.

Overall top-level configuration file would like something like this
```
cmake_minimum_required(VERSION 3.14.5)
set(CMAKE_CXX_STANDARD 14)

project(MTRN3500_Assignment)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
    ${CMAKE_SOURCE_DIR}/bin   #change this directory if desired
)

add_subdirectory(modules/module_A)
add_subdirectory(modules/module_B)
# add_subdirectory(modules/module_C) etc.
```
</details>
</br>

### Module-level CMakeLists.txt

This ```CMakeLists.txt``` exists for each module that you create, in ```project_root/modules/module_*/```.

> Note that name convention "module" doesn't hold any meaning for ```cmake``` -  it is a directory name convention which allows us to organise related files within the same directory.

To let ```cmake``` do its job, you must create a ```CMakeLists.txt``` file for executable you want to produce. This module-level ```CMakeLists.txt``` will contain all building configuration that a module needs in order to produce an executable - which means, you can technically run ```cmake -C build``` in ```project_root/modules/module_*/``` directory, and run ```make``` to build the executable just for that module. (Although it's probably recommended that you simply comment out all other modules from top-level ```CMakeLists.txt``` instead)

> Note: If you do this, ```${CMAKE_SOURCE_DIR}``` won't be ```project_root``` anymore but changes to ```module_name```. If you want it to be ```project_root``` again, simply delete all the ```cmake``` files (other than ```CMakeLists.txt```) in ```module_name``` and rebuild ```cmake``` project at ```project_root```.

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

<details>
<summary> Detailed breakdown </summary>

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

</details>
</br>

## Useful Resources

```cmake``` documentation: https://cmake.org/documentation/

Refer to "Helpful cmakelists" for a sample code to build OpenGL display module.
