#include "shell.h"

#include <iostream>
#include <vector>

#include "ui.h"
#include "config.h"
#include "contract.h"
#include "singleton.h"
#include "message_builder.h"
#include "parameter_manager.h"

using std::vector;
using std::cout;
using std::endl;

namespace tws_shell {

Shell::Shell(ClientSocket* client_socket) : client_socket_(client_socket) {};

int Shell::Run() {
  int code = 0;

  // 启动ClientSocket
  code = this->client_socket_->Start();
  if (0 != code) {
    std::cout << "Starting client socket failed!" << std::endl;
    return 255;
  }

  code = this->RequestWatch();
  if (0 != code) {
    return 255;
  }

  UI* ui = Singleton<UI>::GetInstance();
  if (0 != ui->Init()) {
    exit(255);
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

int Shell::RequestWatch() {
  const vector<string>& watch_list = Singleton<Config>::GetInstance()->get_watch_list();
  for (const string& item : watch_list) {
    RequestWatchBySymbol(item);
  }
  return 0;
}

int Shell::RequestWatchBySymbol(string symbol) {
  //cout << symbol << endl;
  int ticker_id = Singleton<ParameterManager>::GetInstance()->get_next_ticker_id();
  Singleton<ParameterManager>::GetInstance()->CreateTick(ticker_id, symbol);

  Contract c = Contract::CreateStock(symbol);
  ostringstream oss; 
  MessageBuilder::BuildMsgReqMktData(oss, ticker_id, c, "", false);
  client_socket_->Send(oss);
  return 0;
}

int Shell::ProcessIO() {
  return this->client_socket_->Select();
}

}
