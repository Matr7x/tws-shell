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
  // Config
  string address = "127.0.0.1";
  int port = 4001;

  // 创建Shell
  Shell* shell = new Shell(new ClientSocket(address, port));

  // 运行Shell
  // TODO: 返回值判别
  shell->Run();

  return 0;

  //int sock = socket(AF_INET, SOCK_STREAM, 0);

  //struct sockaddr_in addr;
  //memset(&addr, 0, sizeof(addr));
  //addr.sin_family = AF_INET;
  //addr.sin_port = htons(4001);
  //addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  //int code = connect(sock, (struct sockaddr *) &addr, sizeof(addr));

  //std::cout << "code: " << code << std::endl;
  //std::cout << "errno: " << errno << std::endl;

  //std::ostringstream oss;

  //oss << 63 << '\0';

  //int sent = ::send(sock, oss.str().c_str(), oss.str().size(), 0);

  //std::cout << oss.str() << std::endl;

  //std::cout << "sent: " << sent << std::endl;

  //char buf[1024];

  //int received = ::recv(sock, buf, sizeof(buf), 0);

  //std::cout << "received: " << received << std::endl;
  //std::cout << "server version: " << buf << std::endl;
  //std::cout << "tws time: " << &buf[3] << std::endl;

  //return 0;
}

