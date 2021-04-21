#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;

class SocketClient {
  string response;
  public: 
    void callServer();
    void closeSocket();
    string getResponse();
};