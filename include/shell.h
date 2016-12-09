#ifndef TWS_SHELL_SHELL_H_
#define TWS_SHELL_SHELL_H_

#include "client_socket.h"

namespace tws_shell {

class Shell {

public:
  Shell(ClientSocket* client_socket) : client_socket_(client_socket) {};

public:
  // 启动Shell
  int Run();

private:
  // 循环处理IO
  int ProcessIO();

private:
  ClientSocket* client_socket_;

};

}

#endif //TWS_SHELL_SHELL_H_
