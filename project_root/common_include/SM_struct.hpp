//File description: Data struct files for robot software architecture.
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 22 Aug 2020
//Comment up to date?: NO

//only process the header once

#pragma once
#define OFFLINE
// bit position of respective flags. Must match the ModuleFlags declaration order!
constexpr int PROG_ID_PM 	= 0;
constexpr int PROG_ID_GPS 	= 1;
constexpr int PROG_ID_LAS 	= 2;
constexpr int PROG_ID_XBOX = 3;
constexpr int PROG_ID_VEH 	= 4;
constexpr int PROG_ID_DISP = 5;

// These numbers can be arbitary. Used for Switch cases.
constexpr int FLAG_HEARTBEAT_PM = 1;
constexpr int FLAG_HEARTBEAT 	= 2;
constexpr int FLAG_CRITICAL 	= 3;
constexpr int FLAG_SHUTDOWN 	= 4;

// 
constexpr bool HEARTBEAT_DOWN 	= 0;
constexpr bool HEARTBEAT_UP		= 1;
constexpr int FLAG_SET_ALL 		= 0xFF;

// These must match binary executable names of each modules.
constexpr char* BIN_NAME_PM 	= (char*)"run_pm";
constexpr char* BIN_NAME_GPS 	= (char*)"run_gps";
constexpr char* BIN_NAME_LAS 	= (char*)"run_laser";
constexpr char* BIN_NAME_XBOX 	= (char*)"run_xbox";
constexpr char* BIN_NAME_VEH 	= (char*)"run_vehicle";
constexpr char* BIN_NAME_DISP 	= (char*)"run_display";

struct ModuleFlags {
	unsigned char 	pm:1,
					gps:1,
					laser:1,
					xbox:1,
					vehicle:1,
					display:1,
					unused:2;
};

union ExecFlags {
	unsigned char Status;	//can access all heart beats at once
	ModuleFlags Flags;		//can select one heart beat of a module
};

struct P_Management {
	ExecFlags PMheartbeats;
	ExecFlags Heartbeats;
	ExecFlags Critical;
	ExecFlags Shutdown;
	ExecFlags data_ready;
};

struct LaserStruct {
	// double Range[600];
	double xRange[600];
	double yRange[600];
};

struct GPS_Struct {
	double Easting;
	double Northing;
	double Height;
};

struct VehicleStruct {
	double actual_speed;
	double actual_steering;
	bool pursuit_mode;
};
