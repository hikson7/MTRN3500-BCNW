// File description: Shared memory example.
// Created by: Hikari hashida
// Date created: Sep 2020
// to compile: g++ -Wall -std=c++17 -o writer SMObject.cpp writer.cpp

#include <stdio.h>
#include <string>
#include "SMObject.hpp"

constexpr char KEY_FILE_PATH[] = ".shm_key"; // Arbitary file.

int main(int argc, char *argv[]) {
    /* Same as reader.cpp, create/access shared memory */
	std::string create_file("touch ");
	create_file.append(KEY_FILE_PATH);
	system(create_file.c_str());

	std::string path(std::getenv("PWD"));
	path.append("/");
	path.append(KEY_FILE_PATH);

	SMObjectSpace::SMObject writer(path.c_str(), 'P', sizeof(double));

	/* Allocate specified size of memory to be shared */
	if (writer.shmCreate() < 0) {
		writer.pError("Segment memory allcocation failed");
	}
	/* Access shared memory */
	if (writer.shmAccess() < 0) {
		writer.pError("Segment memory attach failed");
	}

    /* write data to shared memory */
	double* data = (double*) writer.pdata_;
	while('Q' != getchar()) {
        *data = rand()/2.0;
		printf("Shared memory Data changed to: %lf\n",*data);
    }
	return 0;
}