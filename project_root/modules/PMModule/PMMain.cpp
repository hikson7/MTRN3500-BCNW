//File description: Process Management file
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 22 Aug 2020
//Comment up to date?: NO

//#define CONIO_H

// #include "mconio.h"     //getch(), kbhit()

// shared memory headers
// #include "SM_object.hpp"

int main(int argc, char *argv[]) {
	
	// ProcessManager PM;

	// PM.startProcess(PROG_ID_DISP);
	// PM.startProcess(PROG_ID_LAS);
	// // startProcess("run_gps", &shm_PM->Heartbeats.Status, GPS_POS);
	// // startProcess("run_laser", &shm_PM->Heartbeats.Status, LAS_POS);
	// // startProcess("run_xbox", &shm_PM->Heartbeats.Status, XBOX_POS);
	// // startProcess("run_vehicle", &shm_PM->Heartbeats.Status, VEH_POS);

	// // shm_PM->Critical.Flags.laser = true;
	// // shm_PM->Critical.Flags.xbox = true;
	// // shm_PM->Critical.Flags.vehicle = true;

	// // shm_PM->data_ready.Status = 0xFF;
	// while (PM.continueProcessManager()) {

	// 	PM.printStatus();
	// 	PM.checkProcess(PROG_ID_DISP);
	// 	// checkProcess("run_gps", shm_PM, GPS_POS);
	// 	// checkProcess("run_vehicle", shm_PM, VEH_POS);
	// 	// checkProcess("run_xbox", shm_PM, XBOX_POS);
	// 	// checkProcess("run_laser", shm_PM, LAS_POS);

	// 	std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	// 	if (kbhit()) break;
	// }
	
	// std::cout << "Process management terminated normally." << std::endl;
	return 0;
}