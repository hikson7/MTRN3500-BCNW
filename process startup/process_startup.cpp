/*
Description: Starter process handling code.
Written by: Hikari Hashida
Date created: Nov 2020
*/

#include <cstdlib>   // open other executables: system()
#include <signal.h>  // kill() signal
#include <string>

/*
Get process id (PID) of a currently running executable name.
*/
int getPID(const std::string process) {
    std::string output, input;

    FILE* stream;
    const int max_buffer = 30;
    char buffer[max_buffer];

    // Terminal command to print pid of an executable
    output.append("pidof ");
    // Executable name
    output.append(process);
    // "R"ead terminal output to a stream
    stream = popen(output.c_str(), "r");

    if (stream) {
        while (!feof(stream))
        if (fgets(buffer, max_buffer, stream) != NULL) {
        // store string pid into input string
            input.append(buffer);
        }
        pclose(stream);
    }
    // convert string to integer
    return std::atoi(input.c_str());
}

bool IsProcessRunning(const std::string processName) {
    // convert string to integer
    int pid = getPID(processName);
    // send signal to process with the pid. if reponds, process is running.
    return pid != 0 && kill(pid, 0) == 0;
}

int main(int argc, char *argv[]) {
    // ttab -w will open a new terminal window.
    std::string executeCommand = "ttab -w exec ./";
    // target executable name to be started.
    std::string programName = "key_hit";
    executeCommand.append(programName);

    // Start program
    system(executeCommand.c_str());

    // Wait until program had started
    while (!IsProcessRunning(programName)) {}

    // Infinite loop until process is no longer running.
    while (IsProcessRunning(programName)) {
        puts("I am still running");
    }
    puts("Process ended");
}
