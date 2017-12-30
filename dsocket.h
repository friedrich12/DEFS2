/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dsocket.h
 * Author: Professor
 *
 * Created on December 28, 2017, 6:54 AM
 */

#ifndef DSOCKET_H
#define DSOCKET_H
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <map>
#include <netdb.h>
#include "DEFS2API.cpp"

#define LISTEN_QUEUE_NUMBER 255
#define BUFLEN 4096

class DSocket
{
public:
    DSocket();
    DSocket(int fd);
    ~DSocket();
    
    int SendTCPMessage(char* msg, int msg_size);
    int StartTCPServer(int port, int address);
    DSocket* AcceptTCPConnection();
    int ConnectToTCPServer(int port, user name);
    int StartUDPServer();
    int ReceiveTCPMessage(char* buffer, int buffer_size);
    
    int CloseSocket();
private:
    int socket_fd;
    sockaddr_in remote;
    sockaddr_in local;
    char buf[BUFLEN];
    char retbuf[BUFLEN];
    socklen_t len;
    socklen_t rlen;
    map<user, string> mymap;
    map<user, int> userIDMap;
    map<user, int> userIDMap;
};

#endif /* DSOCKET_H */

