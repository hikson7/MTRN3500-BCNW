#include <iostream>
// #include <unistd.h>

using namespace std;

int main() {

    char buf[PATH_MAX]; /* PATH_MAX incudes the \0 so +1 is not required */
    char *res = realpath("../text.cpp", buf);
    if (!res) {
        perror("realpath");
        exit(EXIT_FAILURE);
    }

    printf("This source is at %s.\n", buf);
    // return buf;
}