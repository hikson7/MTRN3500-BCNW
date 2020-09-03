//File description: Shared memory bject
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 22 Aug 2020
//Comment up to date?: NO

#pragma once

#include <sys/shm.h>
#include "SM_struct.hpp"

namespace SMObjectSpace {
	class SMObject {

		public:
			SMObject();
			SMObject(const char* path, char key_id, int size);

			~SMObject();
			void SMCreate();
			void SMAccess();
			/* Memory counter function */
			void decrementMemCtr();
		
		private:
			int size_;		//size of shared memory.
			key_t key_;		//key to shared memory.
			int shmid_;		//shared memory ID.

			/* Memory counter variables */
			void 	*mem_ctr_;	
			int 	mem_ctr_id_;
			key_t 	mem_ctr_key_;

		public:
			bool SMCreateError_;
			bool SMAccessError_;
			bool SMKeyPathError_;
			void *pData_;	//pointer to access shared memory data
	};
};