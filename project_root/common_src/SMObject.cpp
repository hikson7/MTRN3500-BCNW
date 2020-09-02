//File description: struct files for MTRN3500 Assignment 2
//Created by: Hikari hashida
//Date created: 10/7/2019
//Date last modified: 20/7/2019
//Comment up to date?: NO
//handy terminal comands:
//ipcs: IPC status - checks for existing shared memory
//ipcrm -M key_: removes memory from given key_
//ipcrm -m ID: removes memory from assigned ID

#include <SMObject.hpp>

SMObject::SMObject(const char* path, const char key_id, int size) {
		
	// PATH_MAX includes the \0 so +1 is not required
	char buf[PATH_MAX]; 
	// find absolute path if local path is given
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

	std::cout << path << std::endl;
	//NOTE: key_id and path together creates a unique "key" for the share memory. Key must be the same when accessed in other executables
	if ((key_ = ftok(path, key_id)) == -1) {
		perror("ftok");
		exit(1);
	}

	std::cout << "key_: " << key_ << std::endl;

	shm_data_ = NULL;
	shm_size_ = size;
	delete_flag_ = 0;
}

SMObject::SMObject() {}

SMObject::~SMObject() {

	if (delete_flag_) {
		//deattach from allocated shared memory
		if (shmdt(shm_data_) < 0) {
			perror("shmdt - shared memory was not detached");
			exit(1);
		}
		std::cout << "segment detached :)" << std::endl;
		//destroy shared memory
		if (shmctl(shmid_, IPC_RMID, NULL) < 0) {
			perror("shmctl - shared memory was not deleted");
			exit(1);
		}
		std::cout << "segment deleted :)" << std::endl;
	} else {
		std::cout << "segment not deleted!" << std::endl;
	}
}

void SMObject::shmCreate()  {
	shmid_ = shmget(key_, shm_size_, IPC_CREAT | 0666); //create shared memory if it does not exist
	if (shmid_ < 0) {
		perror("shmat - shared memory creation failed");
		exit(1);
	}
	std::cout << "shmid_: "<< shmid_ << std::endl;
}

void SMObject::shmAccess() {
	shm_data_ = shmat(shmid_, (void*)0, 0);		//returns void pointer to the SM data
	if (shm_data_ == (void*)(-1)) {
		perror("shmat: shared memory attach failed.");
		exit(1);
	}
}

int SMObject::getShmid() {
	return shmid_;
}

void SMObject::restoreShmid(int original_shmid) {
	if (delete_flag_)
		shmid_ = original_shmid;
}

void SMObject::free() {
	delete_flag_ = true;
}

char *flagHandle(int argc, char *argv[]) {

	int aflag = 0;
	int bflag = 0;
	char *path = NULL;
	int index;
	int c;
	opterr = 0;
	// while ((c = getopt(argc, argv, "abscP:")) != -1)
	while ((c = getopt(argc, argv, "sP:")) != -1)

	switch (c) {
		// case 'a':
		// 	aflag = 1;
		// 	break;
		// case 'b':
		// 	bflag = 1;
		// 	break;
		case 's':
			std::cout << "Process running independently."<< std::endl;
			break;
		case 'P':
			path = optarg; //getopt exeternal variable
			break;
		case '?':
			if (optopt == 'P')
				fprintf (stderr, "Option -%c requires an argument.\n", optopt);
			else if (isprint (optopt))
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else
				fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
			exit(1);
		default:
			abort ();
	}

	// printf ("aflag = %d, bflag = %d, cvalue = %s\n", aflag, bflag, cvalue);

  	for (index = optind; index < argc; index++)
    	printf ("Non-option argument %s\n", argv[index]);
	
	return path;
}