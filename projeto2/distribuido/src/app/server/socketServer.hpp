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

#include "../../controller/lamps/lampsController.hpp"
#include "../../controller/bme280/bme280Controller.hpp"
#include "../../controller/airConditioner/airConditioner.hpp"

class SocketServer 
{
public:
  void runSocketServer();
  void closeSocket();
};