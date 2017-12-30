/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <string>
#include <arpa/inet.h>
#include "ServerClient.h"
#include "dsocket.h"

using namespace std;

int client(){
    unsigned short int port = 1223;
    
    user df;
    df.name = "ClientTest";
    //df->ip = NULL;
   
    char ipv4addr[sizeof(struct in_addr)];
    
    inet_pton(AF_INET, "127.0.0.1", ipv4addr);  
    df.hp = gethostbyaddr(&ipv4addr, sizeof(ipv4addr), AF_INET);
    
    if(df.hp){
        printf("Host name connection with : %s\n", df.hp->h_name);
    }else{
        printf("Error failed to filed:%s\n", hstrerror(h_errno));
    }
    
    /*string ip = "localhost";
    char *cstr = new char[ip.length() + 1];
    strcpy(cstr, ip.c_str());*/
    
    
    DSocket* client = new DSocket();
    client->ConnectToTCPServer(port, df);
    
    //delete [] cstr;*
    
    message incoming;
    client->ReceiveTCPMessage((char*) &incoming, sizeof(incoming));
}