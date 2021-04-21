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

#include "lampsController.hpp"
#include "bme280Controller.hpp"
#include "airConditioner.hpp"
#include "windowController.hpp"
#include "presenceSensorController.hpp"
#include "doorsController.hpp"

class SocketServer 
{
public:
  void runSocketServer();
  void closeSocket();
};