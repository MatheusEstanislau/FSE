#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <string.h>
#include <vector>


using namespace std;

class SocketServer 
{
  void socketTreatment(int clientSocket);
  string response;
  bool alarmState = false;
public:
  void runSocketServer();
  void closeSocket();
  string getResponse();
};