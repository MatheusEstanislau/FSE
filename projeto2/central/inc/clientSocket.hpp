#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;

class ClientSocket {
  string response;
  public: 
    void callServer(int request);
    string getResponse();
    void closeSocket();
};