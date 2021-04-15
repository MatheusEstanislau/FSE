#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

using namespace std;

class Server {
  int response;
  public: 
    void callServer(int request);
    int getResponse();
};