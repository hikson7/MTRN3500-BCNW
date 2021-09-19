//File description: Shared memory class.
//Created by: Hikari hashida
//Date created: Sep 2020

//handy terminal comands:
//ipcs: IPC status - checks for existing shared memory
//ipcrm -M key_: removes memory from given key_
//ipcrm -m ID: removes memory from assigned ID

#include <stdio.h>
#include <string>
#include <cstring>
#include "SMObject.hpp"

extern int errno;

using namespace SMObjectSpace;

SMObject::SMObject() {

	proj_id_ = 0;
	size_ = 0;
	pdata_ = nullptr;
	pmem_ctr_ = nullptr;
	mem_ctr_id_ = 0;
	error_handle_ = 0;
}

SMObject::SMObject(const char* path, const char proj_id, int size) {

	strcpy(path_, path);
	proj_id_ = proj_id;
	size_ = size;
	pdata_ = nullptr;
	pmem_ctr_ = nullptr;
	mem_ctr_id_ = 0;
	error_handle_ = 0;
}

SMObject::~SMObject() {

	if (pdata_ == nullptr) exit(0);
	/* If this is the only process accessing shared memory, delete memory */
	if (*(int*)pmem_ctr_ <= 1) {
		/* deattach shared memory */
		if (shmdt(pdata_) < 0) {
			perror("shmdt - shared memory was not detached"); exit(1);
		}
		if (shmdt((void*)pmem_ctr_) < 0) {
			perror("shmdt - shared memory was not detached for shm ctr"); exit(1);
		}
		/* delete shared memory */
		if (shmctl(shmid_, IPC_RMID, NULL) < 0) {
			perror("shmctl - shared memory was not deleted"); exit(1);
		}
		if (shmctl(mem_ctr_id_, IPC_RMID, NULL) < 0) {
			perror("shmctl - shared memory was not deleted for shm ctr");
		}
	} else {                                               
		*(int*)pmem_ctr_ = *(int*)pmem_ctr_-1;
	}
} 

int SMObject::shmCreate()  {

	char buf[PATH_MAX], *res;
	int key_ = 0, mem_ctr_key_ = 0;

	/* Check for valid path & proj_id */
	if (!(res = realpath(path_, buf))) {
		error_handle_ = errno; return -1;
	}
	if (proj_id_ < 'A' || proj_id_ > 'z') {
		error_handle_ = EBADK; return -1;
	}
	/* Create valid and unique keys */
	if ((key_ = ftok(path_, proj_id_)) == -1) {
		error_handle_ = errno; return -1;
	}
	if ((mem_ctr_key_ = ftok(path_, proj_id_ - KEY_OFFSET)) == -1) {
		error_handle_ = errno; return -1;
	}
	/* Create shared memory */
	if ((shmid_ = shmget(key_, size_, IPC_CREAT | 0666)) < 0){
		error_handle_ = errno; return -1;
	}
	if ((mem_ctr_id_ = shmget(mem_ctr_key_, sizeof(int), IPC_CREAT | 0666)) < 0){
		error_handle_ = errno; return -1;
	}
	
	return EXIT_SUCCESS;
}

int SMObject::shmAccess() {
	/* Attach shared memory with given id */
	if ((pdata_ = shmat(shmid_, (void*)0, 0))==(void*)(-1)) {
		error_handle_ = errno; return -1;
	}
	if ((pmem_ctr_ = shmat(mem_ctr_id_, (void*)0, 0)) == (void*)(-1)) {
		error_handle_ = errno; return -1;
	}
	/* Increment memory counter */
	*(int*)pmem_ctr_ = *(int*)pmem_ctr_ + 1;
	return EXIT_SUCCESS;
}

void SMObject::setUniquePathID(const char* path, const char proj_id) {
	strcpy(path_, path);
	proj_id_ = proj_id;
}

void SMObject::setSize(int size) {
	size_ = size;
}

void SMObject::decrementMemCtr() {
	*(int*)pmem_ctr_ = *(int*)pmem_ctr_ - 1;
}

void SMObject::pError(const char* message) {
	if (error_handle_ > 0)
		perror(message);
	else {
		/* For custom error handling */
		std::string error_msg(message);
		error_msg.append(errorMapping(error_handle_));
		printf("%s\n",error_msg.c_str());
	}
};

const char* SMObjectSpace::errorMapping(int e) {
	switch (e) {
		case EBADK: return EBADK_MSG;
		default: 	return nullptr;
	}
}