#ifndef TWS_SHELL_CLIENT_SOCKET_H_
#define TWS_SHELL_CLIENT_SOCKET_H_

#include <string>

using std::string;

namespace tws_shell {

class ClientSocket {

public:
  ClientSocket(string address, int port) : 
    address_(address), port_(port), sock_(-1) {}

public:
  // 启动ClientSocket
  int Start();

  // 停止ClientSocket
  int Stop();

  // Select
  int Select();

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

private:
  string  address_;
  int     port_;
  int     sock_;

};

} // namespace tws_shell

#endif //TWS_SHELL_CLIENT_SOCKET_H_
