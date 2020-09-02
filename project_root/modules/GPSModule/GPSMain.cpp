// File description: main for GPS Module
// Created by: Hikari hashida
// Date created: 17/7/2019
// Date last modified: 20/7/2019
// Comment up to date?: NO

#include "CRCGeneration.hpp"

struct __attribute__((__packed__)) GPS_info {		//112-bytes (use unpacked to remove padding)
	unsigned int Header; 							//4-bytes
	unsigned char Discards1[40]; 					//unrelated data
	double Northing;
	double Easting;
	double Height;
	unsigned char Discards2[40]; 					//unrelated data
	unsigned int Checksum;
};

int main() {

	/*Implement your code here!*/

	return 0;
}

