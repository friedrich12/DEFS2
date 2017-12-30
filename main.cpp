/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Professor
 *
 * Created on December 28, 2017, 6:52 AM
 */

#include "dsocket.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <unistd.h>

using namespace std;

DSocket::DSocket(){
    len = sizeof(local);
    rlen = sizeof(remote);
}

DSocket::DSocket(int fd){
    socket_fd = fd;
    len = sizeof(local);
    rlen = sizeof(remote);
}

DSocket::~DSocket(){
    this->CloseSocket();
}

int DSocket::SendTCPMessage(char* msg, int msg_size){
    return send(socket_fd, msg, msg_size, 0);
}

int DSocket::ReceiveTCPMessage(char* buffer, int buffer_size){
    int msglen = recv(socket_fd, buffer, buffer_size, 0);
    return msglen;
}

int DSocket::StartTCPServer(int port, int address){
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = address;
    local.sin_port = htons(port);
    
    bind(socket_fd, (struct sockaddr*) &local, len);
    listen(socket_fd, LISTEN_QUEUE_NUMBER);
    
    getsockname(socket_fd, (struct sockaddr *) &local, &len);
    return local.sin_port;
}

DSocket* DSocket::AcceptTCPConnection(){
    DSocket * new_socket = NULL;
    int ac = accept(socket_fd, (struct sockaddr *)0, (socklen_t*) 0);
    if(ac != -1){
        new_socket = new DSocket(ac);
    }
    return new_socket;
}

int DSocket::ConnectToTCPServer(int port, user name){
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0){
        perror("Failed to create socket:");
        close(socket_fd);
        return -1;
    }
    
    memset(&remote, '0', sizeof(remote));
    
    remote.sin_family = AF_INET;
    remote.sin_port = htons(port); 
    
    memcpy(&remote.sin_addr, name.hp->h_addr, name.hp->h_length);
    
    if(connect(socket_fd, (struct sockaddr* )&remote, sizeof(remote)) < 0){
        perror("Failed to connect");
        close(socket_fd);
        return -1;
    }
    return 0;
}


int DSocket::CloseSocket(){
    close(socket_fd);
    return 0;
}

