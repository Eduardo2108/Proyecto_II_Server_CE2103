//
// Created by eduardozumbadog on 20/5/21.
//



#include <iostream>
#include <cstring>
#include "string"
#include "Server.h"

Server *Server::pinstance_{nullptr};
std::mutex Server::mutex_;

Server::Server() {

}

Server *Server::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr) {
        pinstance_ = new Server();
    }
    return pinstance_;
}

int Server::InitServer() {
    cout << ("Listening on port: " + to_string(this->port)) << endl;
    // Create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1) {
        cerr << ("Can't create a socket! Quitting") << endl;
        return -1;
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(this->port);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr *) &hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    // Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    clientSocket = accept(listening, (sockaddr *) &client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr *) &client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        std::ostringstream log;
        log << service;
        cout << ("Client connected in port: " + log.str()) << endl;
    } else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close listening socket
    close(listening);

    // While loop: accept and echo message back to client
    char buf[4096];

    while (true) {
        memset(buf, 0, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == -1) {
            cerr << ("Error in recv(). Quitting") << endl;
            break;
        }

        if (bytesReceived == 0) {
            cout << ("Client disconnected, exiting program...") << endl;
            cout << "Client disconnected " << endl;
            break;
        }

        client_message = string(buf, 0, bytesReceived);
        if (!client_message.empty()) {
            cout << ("Message recieved: " + client_message) << endl;
            const string &response = ServerManager::processRequest(client_message);
            Send(response.c_str());
        }
    }
    // Close the socket
    close(clientSocket);
    return 0;
}

void Server::Send(const char *msg) const {
    int sendRes = send(clientSocket, msg, strlen(msg), 0);
    cout << ("Message sent: " + string(msg)) << endl;

    if (sendRes == -1) {
        std::cout << "Send message failed" << std::endl;
    }
}
