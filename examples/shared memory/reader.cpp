// File description: Shared memory example.
// Created by: Hikari hashida
// Date created: Sep 2020
// to compile: g++ -Wall -std=c++17 -o reader SMObject.cpp reader.cpp
#include <stdio.h>
#include <string>
#include "SMObject.hpp"

constexpr char KEY_FILE_PATH[] = ".shm_key"; // Arbitary file.

int main(int argc, char *argv[]) {

	std::string create_file("touch ");
	create_file.append(KEY_FILE_PATH);
	system(create_file.c_str());

	std::string path(std::getenv("PWD"));
	path.append("/");
	path.append(KEY_FILE_PATH);

	SMObjectSpace::SMObject reader(path.c_str(), 'P', sizeof(double));

	/* Allocate specified size of memory to be shared */
	if (reader.shmCreate() < 0) {
		reader.pError("Segment memory allcocation failed");
	}
	/* Access shared memory */
	if (reader.shmAccess() < 0) {
		reader.pError("Segment memory attach failed");
	}
	/* read content from shared memory */
	double* data = (double*) reader.pdata_;
	while('Q' != getchar())
		printf("Data read from shared memory: %lf\n",*data);
	
	return 0;
}