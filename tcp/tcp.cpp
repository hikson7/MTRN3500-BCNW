// File description: working main file for Laser module (OPP)
// Created by: Hikari hashida
// Date created: 17/7/2019
// Date last modified: 30/7/2019
// Comment up to date?: NO
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

#include <thread>   // sleep
#include <chrono>   //

#include "LaserModule.hpp"
#include "ipc.hpp"  // TCP
#include "smobj.hpp"
#include "mconio.h"  // kbhit()

#define MESSAGE_LEN 2000

std::chrono::milliseconds timespan(75);
std::vector <std::string> removeCh(std::string message, const unsigned char ch);

int main() {

    struct addrinfo Laser_server;
    char id[] = "5118937\n";
    IPC tcp(&Laser_server, "192.168.1.200", "23000", AF_INET, SOCK_STREAM);
    tcp.createSocket();

    int data_size = 0;

    tcp.connectSocket();
    tcp.sendmsg(id);
    tcp.receivemsg(server_reply, MESSAGE_LEN);
    puts("Server reply to 5118937\n: ");

    while (1) {
        
        memset(server_reply, 0, sizeof(server_reply));
        tcp.sendmsg(message, 1);
        data_size = tcp.receivemsg(server_reply, MESSAGE_LEN);
        std::vector <std::string> laser_data = removeCh(server_reply, ' ');

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

std::vector <std::string> removeCh(std::string message,
                                                const unsigned char ch) {
    std::vector <std::string> result;
    int pos = 0;
    int j = 0;
    int len = 0;
    bool flag = 1;
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ch) {
            result.push_back(message.substr(pos, len));
            len = 0;
            pos = i+1;
            j++;
            continue;
        }
        len++;
    }
    result.push_back(message.substr(pos, len));
    return result;
}