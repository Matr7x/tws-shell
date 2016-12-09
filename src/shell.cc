#include "shell.h"

#include <iostream>

namespace tws_shell {

int Shell::Run() {
  int code = 0;

  // 启动ClientSocket
  code = this->client_socket_->Start();
  if (0 != code) {
    std::cout << "Starting client socket failed!" << std::endl;
    return 255;
  }

  // 循环处理IO
  while(0 == code) {
    code = Shell::ProcessIO();
  }

  // 检查code
  if (0 != code) {
    return 255;
  }

  return 0;
}

int Shell::ProcessIO() {
  return this->client_socket_->Select();
}

}
