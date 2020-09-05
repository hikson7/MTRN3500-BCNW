# MTRN3500 Base Code for Non-Windows
This repository is designed for real Windows nayers who can't deal with running Virtual Environment on their MacOS. Following topics are covered in the example codes.

- Shared memory.
- Project directory structuring with ```cmake```.
    - sample ```cmake``` configuration file i.e. ```CMakeLists.txt``` for including OpenGL/Glut libraries.
- Keyboard hit i.e. ```kbhit()```.

Coming...
- process startup.
- xbox controller using SDL library.

## Requirements

- ```cmake```

### Installations
#### With Homebrew
```
$ brew install cmake
```
Don't have Homebrew installed? I highly recommend installing it ASAP! Checkout https://zellwk.com/blog/homebrew/
#### Normal installation
Visit https://cmake.org/install/ and follow the instructions.

To check if it is installed correctly, you can run ``` cmake --version ```.
```
$cmake --version                                                                
cmake version 3.18.1
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```
#### Trouble shooting
- ```cmake``` is not found from the command line terminal.
1. Make sure you have ```/usr/local/bin``` as ```PATH``` in ```~/.zshrc``` (or``` ~/.bashrc``` for OS older than Catalina). To do this:
    ```
    $ export PATH="/usr/local/bin:$PATH"
    $ source ~/.zshrc       # or ~/.bashrc
    ```
    Now your terminal should find ```cmake``` as a command. Note that you need to run ```source ~/.zshrc``` to take effect for that terminal straight away. For every new terminal, it should work without re running above commands.


## Usage

### ```cmake```

In this project, we will be creating multiple processes running under separate executables. We can use conventional way of compiling the code that is ```g++ -o ...``` and repeat it for all modules, one by one.

As you can imagine, you'll find yourself doing such a trivial and tedious task, over and over all while fighting off some nasty bugs ... OR we can use ```cmake```!

Once setup correctly (example code/project structure provided in this repo, lucky you!), all you need to do is run ```make```, and all executables will be built!

To create ```cmake``` project, go to root project directory, then run ```cmake```.
```
$ cd project_root/
$ cmake -B build
```
This should create a build folder (if it didn't exist before), and add all necessary ```cmake``` configurations will be created.

#### Building the project
To build all files and produce executables, run following at your root project directory:
```
# at project_root/
$ make -C build
```
Now you should see executables in ```project_root/bin``` folder. There should be an executable for each module.


To clean ```cmake``` project, simply delete ```project_root/build```

### Shared memory object
Shared memory object class ```SMObject``` is implemented for use in MacOS (or Linux, currently untested).

#### Creating shared memory
Initialise SMObject by calling SMObject constructor.
```
using namespace SMObjectSpace;
SMObject::SMObject(
    const char* path,       // Valid path to a existing file.
    const char proj_id,     // unique id for that shared memory segment.
    int size                // size of shared memory.
);
```
Then create shared memory with ```shmCreate()``` and access shared memory with ```shmAccess()```.

#### Error checking/ debugging
Both ```shmCreate()``` and ```shmAccess()``` sets ```error_handle_``` to appropriate ```errno``` or custom error value. To take full advantage of custom errors, use ```pError()``` instead of standard ```perror()```.

#### Note on Memory leak
If the process/program terminates successfully (controller termination, so that destructor ```~SMObject()``` is called), it should take care of freeing or not freeing the shared memory. e.g. if another process is currently using the shared memory, it will not free the memory upon exiting of the program.

This is achieved simply by keeping track of how many processes have access to the shared memory, using ```*pmem_ctr_```. Upon successful call of ```shmAccess()```, ```*pmem_ctr_``` is incremented, and upon successful call of ```~SMObject()``` (upon successful termination of a process) it will decrement the counter.

You do however, need to make sure if a process terminates unexpectedly, you decrement the counter manually in your code with ```decrementMemCtr()```. 

## Useful resources

Detailed explanations about shared memory is presented in this (very easy to follow) website. Highly recommend to use this as your bible if you're facing some bugs from shared memory!

Shared memory: http://beej.us/guide/bgipc/html/multi/shm.html#shmcreat

TCP/IP: http://beej.us/guide/bgnet/html/
