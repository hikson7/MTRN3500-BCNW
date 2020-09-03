//File description: struct files for MTRN3500 Assignment 2
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 20/7/2019
//Comment up to date?: NO
//handy terminal comands:
//ipcs: IPC status - checks for existing shared memory
//ipcrm -M key_: removes memory from given key_
//ipcrm -m ID: removes memory from assigned ID
#include <iostream>
#include "SMObject.hpp"

using namespace SMObjectSpace;
SMObject::SMObject(const char* path, const char key_id, int size) {
		
	char buf[PATH_MAX]; 
	char *res = realpath(path, buf);

	if (!res) {
        // perror("realpath");
        // exit(EXIT_FAILURE);

		std::string create_file("cat > ");
		create_file += path;

		#pragma clang diagnostic push
   		#pragma clang diagnostic ignored "-Wunknown-escape-sequence"
		create_file += "\ ^D";
		#pragma clang diagnostic pop
		system(create_file.c_str());
    }

	if (key_id < 'A' || key_id > 'z') {
		std::cout << "You must choose a key_id from alphabetical characters. i.e. a,A,b,B,...,z,Z" << std::endl;
	}

	//NOTE: key_id and path together creates a unique "key" for the share memory. Key must be the same when accessed in other executables
	if ((key_ = ftok(path, key_id)) == -1) {
		perror("ftok");
		exit(1);
	}
	
	if ((mem_ctr_key_ = ftok(path, key_id-58)) == -1) {
		perror("ftok");
		exit(1);
	}

	pData_ = NULL;
	size_ = size;
}

SMObject::SMObject() {}

SMObject::~SMObject() {
	if (*(int*)mem_ctr_ <= 1) {
		if (shmdt(pData_) < 0) {
			perror("shmdt - shared memory was not detached");
			exit(1);
		}
		if (shmdt((void*)mem_ctr_) < 0) {
			perror("shmdt - shared memory was not detached for shm ctr");
			exit(1);
		}
		std::cout << "segment detached :)" << std::endl;
		//destroy shared memory
		if (shmctl(shmid_, IPC_RMID, NULL) < 0) {
			perror("shmctl - shared memory was not deleted");
			exit(1);
		}
		if (shmctl(mem_ctr_id_, IPC_RMID, NULL) < 0) {
			perror("shmctl - shared memory was not deleted for shm ctr");
			exit(1);
		}
		std::cout << "segment deleted :)" << std::endl;
	} else {
		*(int*)mem_ctr_ = *(int*)mem_ctr_ - 1;
		std::cout << *(int*)mem_ctr_ << "\n";
		std::cout << "segment not deleted!" << std::endl;
	}
}

void SMObject::SMCreate()  {
	shmid_ = shmget(key_, size_, IPC_CREAT | 0666); //create shared memory if it does not exist
	if (shmid_ < 0) {
		perror("shmat - shared memory creation failed");
		exit(1);
	}
	//
	mem_ctr_id_ = shmget(mem_ctr_key_, sizeof(int), IPC_CREAT | 0666); 
	if (mem_ctr_id_ < 0) {
		perror("shmat - shared memory creation failed for shared memory mem_ctr_");
		exit(1);
	}

	std::cout << "shmid_: "<< shmid_ << std::endl;
}

void SMObject::SMAccess() {
	pData_ = shmat(shmid_, (void*)0, 0);		//returns void pointer to the SM data
	if (pData_ == (void*)(-1)) {
		perror("shmat: shared memory attach failed");
		exit(1);
	}
	mem_ctr_ = shmat(mem_ctr_id_, (void*)0, 0);		//returns void pointer to the SM data
	if (mem_ctr_ == (void*)(-1)) {
		perror("shmat: shared memory attach failed for shared memory mem_ctr_");
		exit(1);
	}
	*(int*)mem_ctr_ = *(int*)mem_ctr_ + 1;
}

void SMObject::decrementMemCtr() {
	*(int*)mem_ctr_ = *(int*)mem_ctr_ - 1;
}