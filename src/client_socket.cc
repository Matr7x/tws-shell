#include "client_socket.h"

#include "message_builder.h"

#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>

using std::cout;
using std::endl;
using std::ostringstream;

namespace tws_shell {

int ClientSocket::Start() {
  int code = 0;

  // Connect to server
  code = this->Connect();
  if (0 != code) {
    return 255;
  }

  // Send CLIENT VERSION to Server
  code = this->SendClientVersion();
  if (0 != code) {
    return 255;
  }

  // Receive and process CONNECTION RESPONSE
  code = this->ProcessConnectionResponse();
  if (0 != code) {
    return 255;
  }

  // Set socket to non blocking
  code = this->SetNonBlockingMode();
  if (0 != code) {
    return 255;
  }
  
  // Start API
  code = this->StartApi();
  if (0 != code) {
    return 255;
  }

  return 0;
}

int ClientSocket::Stop() {
  return 0;
}

int ClientSocket::Select() {
  fd_set in_set, error_set;

  struct timeval time_val;
  time_val.tv_usec = 0;
  time_val.tv_sec = 0;

  FD_ZERO(&in_set);
  FD_ZERO(&error_set);

  FD_SET(this->sock_, &in_set);
  FD_SET(this->sock_, $error_set);

  int code  = ::select(this->sock_ + 1, &in_set, null, &error_set, &time_val);

  if (0 == code) {
    return 0;
  }

  if (ret < 0) {
    return 1;
  }

  if (FD_ISSET(this->sock_, &error_set)) {
    // TODO: Socket Error
    cout << "Socket Error" << endl;
  }

  if (FD_ISSET(this->sock_, &in_set)) {
    this->Receive();
  }

  return 0;
}

int ClientSocket::Receive() {
  char buf[8192];
  memset(buf, sizeof(buf), 0);
  int received = receive(this->sock_, buf, sizeof(buf), 0);

  int processed = 0;

  int msg_id;
  int decoded = Decoder<int>::Decode(buf, sizeof(buf), msg_id);

  if (decoded < 0) {
    return 255;
  }

  processed += decoded;

  switch(msg_id) {
    case MANAGED_ACCTS: 
      break;
    case NEXT_VALID_ID:
      break;
  }

  this->DecodeMessage()
}

int ClientSocket::Connect() {
  // Create socket
  this->sock_ = socket(AF_INET, SOCK_STREAM, 0);

  // Build Sock Addr
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(this->port_);
  addr.sin_addr.s_addr = inet_addr(this->address_.c_str());

  int code = connect(this->sock_, (struct sockaddr *) &addr, sizeof(addr));

  if (0 != code) {
    cout << "Connecting to server failed, Error No [" << errno << "]!" << endl;
    return 255;
  }

  return 0;
}

int ClientSocket::SendClientVersion() {
  ostringstream oss; 
  MessageBuilder::BuildMsgClientVersion(oss);
  // TODO: 判断send是否成功
  ::send(sock_, oss.str().c_str(), oss.str().size(), 0);
  return 0;
}

int ClientSocket::ProcessConnectionResponse() {
  // TODO: Need to restuct
  char buf[1024];
  /*int received = */::recv(this->sock_, buf, sizeof(buf), 0);

  cout << "Server Version: " << buf << endl;
  cout << "TWS Time: " << &buf[3] << endl;
  return 0;
}

int ClientSocket::StartApi() {
  ostringstream oss; 
  MessageBuilder::BuildMsgStartApi(oss);
  /*int sent = */::send(sock_, oss.str().c_str(), oss.str().size(), 0);

  //cout << "sent: " << sent << endl;

  //char buf[1024];
  ///*int received = */::recv(this->sock_, buf, sizeof(buf), 0);

  //cout << "message Id: " << buf << endl;

  ///*int received = */::recv(this->sock_, buf, sizeof(buf), 0);

  //cout << "message Id: " << buf << endl;

  ///*int received = */::recv(this->sock_, buf, sizeof(buf), 0);

  //cout << "message Id: " << buf << endl;
  return 0;
}

int ClientSocket::SetNonBlockingMode() {
  int flags = fcntl(this->sock_, F_GETFL); 
  if (-1 == flags) {
    cout << "Get socket flags failed, Error No [" << errno << "]!" << endl;
    return 255;
  }

  if (-1 == fcntl(this->sock_, F_SETFL, flags | O_NONBLOCK)) {
    cout << "Set socket flags failed, Error No [" << errno << "]!" << endl;
    return 255;
  }

  return 0;
}

int ClientSocket::Close() {
  return 0;
}

} // namespace tws_shell
