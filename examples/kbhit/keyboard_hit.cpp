// File description: Usage of non-blocking kbhit() and delay in C++.
// Created by: Hikari hashida
// Date created: Sep 2020
// to compile: g++ -Wall -std=c++17 -o key_hit SMObject.cpp keyboard_hit.cpp

#include <stdio.h>
#include <thread>   // sleep_for, milliseconds
#include "mconio.h" // kbhit()

int main() {

    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        printf("I will continue until you hit Enter\n");
        if (kbhit()) break;
    }
    return 0;
}