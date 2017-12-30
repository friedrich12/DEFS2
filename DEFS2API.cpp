/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define PAYLOAD_SIZE 4096

using namespace std;


// Message Type
enum message_type{
    CONNECT_OK = 1,
    TRACK = 10,
    TRACK_CONFIRM = 15,
    STOP = 20,
    STOP_CONFIRM = 25,
    SUCCESS = 30,
    FAILURE = 40,
    QUIT = 50
};

// Message Structure
struct message{
    message_type type;
    char payload[PAYLOAD_SIZE];
    string text;
};

struct user{
    hostent *hp;
    string name;
    string ip;
};

// Payload structure
struct data{
    // What data
};