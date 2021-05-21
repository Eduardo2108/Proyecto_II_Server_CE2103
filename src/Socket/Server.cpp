//
// Created by eduardozumbadog on 20/5/21.
//



#include <iostream>
#include <cstring>
#include "string"
#include "Server.h"

Server *Server::unique_instance = NULL;

Server::Server() {

}

Server *Server::getInstance() {
    if (unique_instance == NULL) {
        unique_instance = new Server(port, size);
    }
    return unique_instance;
}