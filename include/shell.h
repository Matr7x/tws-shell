#ifndef TWS_SHELL_SHELL_H_
#define TWS_SHELL_SHELL_H_

#include "client_socket.h"

namespace tws_shell {

class Shell {

public:
  Shell(ClientSocket* client_socket);

public:
  Shell();
  // 启动Shell
  int Run();

  // 启动股价Watch
  int RequestWatch();

private:
  // 循环处理IO
  int ProcessIO();

  // 通过Symbol进行Request
  int RequestWatchBySymbol(string symbol);

private:
  ClientSocket* client_socket_;

};

}

#endif //TWS_SHELL_SHELL_H_
