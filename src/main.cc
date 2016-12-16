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
#include "config.h"
#include "singleton.h"
#include "event_handler.h"
#include "message_processor.h"

using tws_shell::Shell;
using tws_shell::Config;
using tws_shell::Singleton;
using tws_shell::ClientSocket;
using tws_shell::EventHandler;
using tws_shell::MessageProcessor;

int main(int argc, char* argv[]) {
  // 加载配置
  Config* config = Singleton<Config>::GetInstance();
  if (0 != config->Init()) {
    exit(255);
  }

  // 创建Shell
  Shell* shell = new Shell(new ClientSocket(new MessageProcessor(new EventHandler), config->get_host(), config->get_port()));

  // 运行Shell
  // TODO: 返回值判别
  shell->Run();

  return 0;
}

