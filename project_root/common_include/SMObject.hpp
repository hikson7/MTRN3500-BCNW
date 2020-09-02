//File description: Shared memory bject
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 22 Aug 2020
//Comment up to date?: NO

#pragma once

#include <sys/shm.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#include <cstdlib>
#include <typeinfo>
#include <iostream>

#include "SM_struct.hpp"

char *flagHandle(int argc, char *argv[]);

class SMObject {

	public:
		SMObject();
		SMObject(const char* path, char key_id, int size);

		~SMObject();
		void shmCreate();
		void shmAccess();

		int getShmid();
		void restoreShmid(int original_shmid);
		void free();

	private:
		int shm_size_;		//size of shared memory.
		key_t key_;			//key to shared memory.
		int shmid_;			//shared memory ID.
		bool delete_flag_;	//flag to delete shared memory upon exit.

	public:
		void *shm_data_;	//pointer to access shared memory data
};
