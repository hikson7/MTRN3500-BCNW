# MTRN3500 sample code for non-Windows users

TODO

* Shared memory: explain why we need shared memory.
    * virtual memory are different for each process
    * OS provides us with a method to share regions of memory
* Add screenshots of how to clean up old shared memory, when not handled properly
* process startup

The purpose of this repository is to provide some starting code for UNSW MTRN3500 - Computing Applications in Mechatronics Systems. In particular, it is aimed to provide code otherwise unavailable for non-Windows users. However, some components of this repository may be helpful for those wanting to move away from a particular integrated development environment (IDE) i.e. build large projects without Microsoft Visual Studio (which is different from Visual Studio Code).

## Contents

- Shared memory class (Using Unix (i.e. Linux/MacOS) functions, without Windows dependent libraries)
- Project directory structuring with ```cmake```.
- Keyboard hit i.e. ```kbhit()```.

Coming...
- process startup.
- xbox controller using SDL library.

Please refer to appropriate folder/directory of interest.
