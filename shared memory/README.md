# Shared memory object

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

Shared memory object class ```SMObject``` is implemented for use in MacOS (or Linux, currently untested).

Initialise SMObject by calling SMObject constructor.
```
using namespace SMObjectSpace;
SMObject::SMObject(
    const char* path,       // Valid path to a existing file.
    const char proj_id,     // unique id for that shared memory segment.
    int size                // size of shared memory.
);
```
## Creating shared memory

Why do we need these arguments? When we create shared memory using ```shmget()```, it requires a "unique key", and for other processes/programs to access the same shared memory space, we provide it with the same key in order to access it.

### Key to Memory
This key is totally arbitrary, and it can be any ```long``` value. For example it could something like ```key=1234```. And we simply use the same key value in another process to access shared memory.

### The problem with 'arbitrary' key
But if by chance, any other program (that you didn't design to share the memory with) happen to use the same key, they will have the access to that key. We probably don't want that!

### Unique key generation
Long story short, we need a truly unique key, and ```ftok()``` does just that. It takes a path to an existing file in your system and an arbitrary, 8-bit int i.e. ```char``` to create a unique key.

## Attaching shared memory


## Memory counter
In case your wondering what the memory counter stuff that's included in SMObject class (like ```decrementMemCtr()```), it's actually related to keeping track of memory management and to prevent leaky memory.

Basically, memory counter is incremented whenever that particular shared memory is accessed by a process, and decremented when the memory is no longer used by a process.

When a program terminates, in the destructor ```~SMObject()``` it checks if the memory counter is <= 1. If it's more than 2, it means that another program is still using the shared memory; so the process simply deattaches from the memory and doesn't delete the it. If the memory counter is 1, it can safely deattach and delete, to prevent memory leak.

### Unexpected termination
All of that sounds nice and neat, but it will work memory-leak-free if and only if each process terminate successfully! If for example, you decide to interrupt and quit the program by sending all powerful ```^C``` in your terminal, the destructor won't be called. Which mean, the memory counter doesn't get decremented!

Can you hear the leaky memory? When even a single program dies this way, the counter will always be greater than 1, which means the memory will never get freed by the program; unless you decrement it using ```decrementMemCtr()```!

```decrementMemCtr()``` is pretty self explanatory; once called, it simply decrements the memory counter. 

I'll leave it up to you to decide where and when to call this function, that's a software design decision and hopefully you'll enjoy learning about it in this course! (little hint: which module monitors all processes?)

# Useful resources
Shared memory: http://beej.us/guide/bgipc/html/multi/shm.html#shmcreat