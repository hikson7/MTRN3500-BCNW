# MTRN3500 Base Code for Non-Windows
MTRN3500 Base Code for Non-Windows users.

## Requirements

## Usage


## Theory

### Shared memory object

Share memory object can be created by calling SMObject constructor.
```
using namespace SMObjectSpace;
SMObject::SMObject(
    const char* path,
    const char key_id,
    int size
);
```
The way 
NOTE: key_id and path together creates a unique "key" for the share memory. Key must be the same when accessed in other executables

```
shmid_ = shmget(key_, size_, IPC_CREAT | 0666); //create shared memory if it does not exist
```