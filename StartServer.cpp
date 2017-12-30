/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <arpa/inet.h>
#include "ServerClient.h"
#include "dsocket.h"


using namespace std;


int server(){
    unsigned short int port = 1223;
    int ip_addr = inet_addr("127.0.0.1");
    DSocket* TCPServer = new DSocket();
    TCPServer->StartTCPServer(1234, ip_addr);
    
    DSocket* connection = TCPServer->AcceptTCPConnection();
    
    message outgoing;
    outgoing.type = CONNECT_OK;
    outgoing.text = "This is awesome";
    connection->SendTCPMessage((char*) &outgoing, sizeof(outgoing));
    
    return 0;
}
