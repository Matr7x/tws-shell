#ifndef TWS_SHELL_CLIENT_SOCKET_H_
#define TWS_SHELL_CLIENT_SOCKET_H_

#include <string>
#include <sstream>

#include "message_processor.h"

using std::string;
using std::ostringstream;

namespace tws_shell {

class ClientSocket {

public:
  ClientSocket(MessageProcessor* message_processor, string address, int port) : 
    message_processor_(message_processor), address_(address), port_(port), sock_(-1) {}

public:
  // 启动ClientSocket
  int Start();

  // 停止ClientSocket
  int Stop();

  // Select
  int Select();

  // Send
  int Send(ostringstream& oss);

private:
  // 连接服务器
  int Connect();

  // 向Server发送版本号
  int SendClientVersion();

  // 处理连接响应
  int ProcessConnectionResponse();
  
  // 向Server发送ClientID
  int SendClientId();

  // 启动API
  int StartApi();

  // 设置Socket为非阻塞
  int SetNonBlockingMode();

  // 关闭连接
  int Close();

  // 接收消息
  int Receive();

  // 解码消息
  int DecodeMessage();

private:
  MessageProcessor* message_processor_;

  string  address_;
  int     port_;
  int     sock_;

};

} // namespace tws_shell

#endif //TWS_SHELL_CLIENT_SOCKET_H_
