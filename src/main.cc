#include <string>
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iomanip>
#include <stdlib.h>

#include "shell.h"

using tws_shell::ClientSocket;
using tws_shell::Shell;

int main(int argc, char* argv[]) {
  // 配置
  string address = "127.0.0.1";
  int port = 4001;

  // 创建Shell
  Shell* shell = new Shell(new ClientSocket(address, port));

  // 运行Shell
  // TODO: 返回值判别
  shell->Run();

  return 0;
}

