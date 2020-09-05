# Shared memory object
```
class SMObject {

		public:
			SMObject();
			SMObject(const char* path, char proj_id, int size);

			~SMObject();
			int shmCreate();
			int shmAccess();
			void setUniquePathID(const char* path, const char proj_id);
			void setSize(int size);
			
			/* Memory counter function */
			void decrementMemCtr();

			/* Error handling */
			void pError(const char* message);
		
		public:
			int error_handle_;
			void *pdata_;		//pointer to access shared memory data

		private:
			int size_;				//size of shared memory.
			int shmid_;				//shared memory ID.
			char path_[PATH_MAX];	//valid global path to a file.
			uint8_t proj_id_;		//valid 8-bit id.

			/* Memory counter variables */
			void 	*pmem_ctr_;	
			int 	mem_ctr_id_;
	};
```


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