//File description: Shared memory class.
//Created by: Hikari hashida
//Date created: Sep 2020

#pragma once
#include <limits.h>
#include <sys/shm.h>
#include <string>

namespace SMObjectSpace {

	/* Custom Error flag */
	enum ErrorFlags {
		EBADK = -2
	};
	constexpr char EBADK_MSG[] 	= ": key_id out of range.";
	constexpr char KEY_OFFSET 	= 58;
	const char* errorMapping(int e);

	class SMObject {

		public:
			SMObject();
			SMObject(const char* path, char proj_id, int size);

			~SMObject();
			int shmCreate();
			int shmAccess();
			void setUniquePathID(const char* path, const char proj_id);
			void setSize(int size);
			
			/* Memory counter function */
			void decrementMemCtr();

			/* Error handling */
			void pError(const char* message);
		
		public:
			int error_handle_;
			void *pdata_;		//pointer to access shared memory data

		private:
			int size_;				//size of shared memory.
			int shmid_;				//shared memory ID.
			char path_[PATH_MAX];	//valid global path to a file.
			uint8_t proj_id_;		//valid 8-bit id.

			/* Memory counter variables */
			void 	*pmem_ctr_;	
			int 	mem_ctr_id_;
	};
};