//
// Created by eduardozumbadog on 20/5/21.
//

#ifndef PROYECTO_II_SERVER_CE2103_SERVER_H
#define PROYECTO_II_SERVER_CE2103_SERVER_H


#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
#include <string>
#include <thread>
#include <sstream>
#include <mutex>

#include "../ServerManager.h"

using namespace std;

class Server {

private:
    static Server *pinstance_;

    static std::mutex mutex_;

protected:
    Server();

private:

    int clientSocket{};
    string client_message;
    int port = 54000;

public:
    Server(Server &other) = delete;

    void operator=(const Server &) = delete;

    static Server *GetInstance();

    /**
     * Method for initializing the server on the port specified
     * @return exit code from copiler.
     */
    int InitServer();

    /**
     * Method for sending a message to the client.
     * @param msg string of the message to be sent.
     */
    void Send(const char *msg) const;
};

#endif //PROYECTO_II_SERVER_CE2103_SERVER_H
