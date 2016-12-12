#include "client_socket.h"

#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/fcntl.h>
#include <sys/select.h>
#include <assert.h>

#include "message_builder.h"
#include "message_processor.h"
#include "decoder.h"
#include "defines.h"

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

  
  // Begin Req Contract Detail
  
  Contract c;
  c.symbol = "UVXY";
  c.sec_type = "STK";
  c.exchange = "SMART";
  c.currency = "USD";

  int ticker_id = 1;
  string end_date_time = "20161210 00:00:00 EST";
  string duration = "1800 S";
  string bar_size = "1 secs";
  string what_to_show = "TRADES";
  int use_rth = 0;
  int format_date = 2;

  ostringstream oss; 
  MessageBuilder::BuildMsgReqHistoricalData(oss, ticker_id, c, end_date_time, duration, bar_size, what_to_show, use_rth, format_date);
  ::send(sock_, oss.str().c_str(), oss.str().size(), 0);

  //ostringstream oss; 
  //MessageBuilder::BuildMsgReqMktData(oss, 0, c, "", false);

  //ostringstream oss; 
  //MessageBuilder::BuildMsgReqAccountSummary(oss, 0, "All", 
      //"AccountType,NetLiquidation,TotalCashValue,SettledCash,AccruedCash,BuyingPower,EquityWithLoanValue,PreviousDayEquityWithLoanValue,GrossPositionValue,RegTEquity,RegTMargin,SMA,InitMarginReq,MaintMarginReq,AvailableFunds,ExcessLiquidity,Cushion,FullInitMarginReq,FullMaintMarginReq,FullAvailableFunds,FullExcessLiquidity,LookAheadNextChange,LookAheadInitMarginReq,LookAheadMaintMarginReq,LookAheadAvailableFunds,LookAheadExcessLiquidity,HighestSeverity,DayTradesRemaining,Leverage");
  //MessageBuilder::BuildMsgReqPositions(oss);
  //::send(sock_, oss.str().c_str(), oss.str().size(), 0);
  
  // End ReqConstract Detail

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
  FD_SET(this->sock_, &error_set);

  int code  = ::select(this->sock_ + 1, &in_set, NULL, &error_set, &time_val);

  if (0 == code) {
    //cout << "Time out" << endl;
    return 0;
  }

  if (code < 0) {
    cout << "Error" << endl;
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
  // XXX: 接收代码待优化
  char buf[8192];
  int received = 0;
  do {
    // FIXME: 当buffer填满时会存在边界bug
    memset(buf, sizeof(buf), 0);
    received = ::recv(this->sock_, buf, sizeof(buf), 0);

    if (0 == received) {
      cout << "Connection broken" << endl;
      exit(255);
    }

    if (received < 0 && EAGAIN == errno) {
      break;
    }

    if (received < 0) {
#include <errno.h>
      cout << "Error: " << strerror(errno) << endl;
      exit(255);
    }

    cout << "Received: " << received << endl;

    int processed = 0;

    while (processed < received) {
      int msg_id;
      int decoded = Decoder::Decode(&buf[processed], received, msg_id);

      //cout << "Message Id: " << msg_id << endl;

      if (decoded < 0) {
        return 255;
      }

      processed += decoded;

      switch(msg_id) {
        case MANAGED_ACCTS: {
          int c = MessageProcessor::ProcessManagedAccts(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case NEXT_VALID_ID: {
          int c = MessageProcessor::ProcessNextValidId(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case ERR_MSG: {
          int c = MessageProcessor::ProcessErrMsg(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case CONTRACT_DATA: {
          int c = MessageProcessor::ProcessContractData(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case CONTRACT_DATA_END: {
          int c = MessageProcessor::ProcessContractDataEnd(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case TICK_STRING: {
          int c = MessageProcessor::ProcessTickString(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case TICK_PRICE: {
          int c = MessageProcessor::ProcessTickPrice(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case TICK_SIZE: {
          int c = MessageProcessor::ProcessTickSize(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case ACCOUNT_SUMMARY: {
          int c = MessageProcessor::ProcessAccountSummary(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case ACCOUNT_SUMMARY_END: {
          int c = MessageProcessor::ProcessAccountSummaryEnd(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case POSITION_DATA: {
          int c = MessageProcessor::ProcessPositionData(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case POSITION_END: {
          int c = MessageProcessor::ProcessPositionEnd(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        case HISTORICAL_DATA: {
          int c = MessageProcessor::ProcessHistoricalData(&buf[processed], received - processed);
          if (c < 0) {
            return 255;
          }
          processed += c;
          break;
        }
        default: {
          cout << "Unknow message id: " << msg_id << endl;
          exit(255);
        }
      }
    }

    //cout << "Processed: " << processed << endl;
    assert(processed == received);
  } while (received > 0 || (received < 0 && EAGAIN == errno));

  
//#include <errno.h>  
  //cout << "Errno: " << strerror(errno) << endl;

  return 0;
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
  int size = ::recv(this->sock_, buf, sizeof(buf), 0);
  if (size < 0) {
    return 255;
  }

  cout << "Received :" << size << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  string tws_time;

  DECODE(version);
  DECODE(tws_time);

  assert(processed == size);

  cout << endl;
  cout << "[Begin] ### Server Info ###" << endl;
  cout << "Server Version: " << version << endl;
  cout << "TWS Time: " << tws_time << endl;
  cout << "[End] ### Server Info ###" << endl;
  cout << endl;

  return 0;
}

int ClientSocket::StartApi() {
  ostringstream oss; 
  MessageBuilder::BuildMsgStartApi(oss);
  int sent = ::send(sock_, oss.str().c_str(), oss.str().size(), 0);

  // XXX: 待优化
  if (sent < 0) {
    return 255;
  }

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
