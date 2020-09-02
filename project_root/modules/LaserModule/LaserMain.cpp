// File description: working main file for Laser module (OPP)
// Created by: Hikari hashida
// Date created: 17/7/2019
// Date last modified: 30/7/2019
// Comment up to date?: NO

#include <thread>					//sleep
#include <chrono>					

std::chrono::milliseconds timespan(75);
int main() {

	/* implement your code here */

	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	return 0;
}