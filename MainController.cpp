/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "ServerClient.h"

using namespace std;

int main(){
    
    int ans;
    cout << "Enter 1 for server, 2 for client:";
    cin >> ans;
    
    switch (ans){
        case 1:
            cout << "Server has been activated" << endl;
            server();
            break;
        case 2:
            cout << "Client has been activated" << endl;
            client();
            break;
        default:
            cout << "Sorry I didn't get that" << endl;
            break;
    }
    return 0;
}