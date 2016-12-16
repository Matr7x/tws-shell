#ifndef TWS_MESSAGE_BUILDER_SOCKET_H_
#define TWS_MESSAGE_BUILDER_SOCKET_H_

#include <sstream>

#include "contract.h"

using std::ostringstream;

namespace tws_shell {

class MessageBuilder {

public:
  // 客户端版本
  static void BuildMsgClientVersion(ostringstream& oss);

  // 启动API
  static void BuildMsgStartApi(ostringstream& oss);

  // 请求合约细节
  static void BuildMsgReqContractDetails(ostringstream& oss, int req_id, Contract& contract);

  // 请求市场数据
  static void BuildMsgReqMktData(ostringstream& oss, int ticker_id, Contract& contract, string generic_ticks, bool snapshot);

  // 请求账户概要
  static void BuildMsgReqAccountSummary(ostringstream& oss, int req_id, const string& group_name, const string& tags);

  // 请求头寸
  static void BuildMsgReqPositions(ostringstream& oss);

  // 请求历史数据
  static void BuildMsgReqHistoricalData(ostringstream& oss, long ticker_id, const Contract& contract, const string& end_date_time, const string& duration, const string& bar_size, const string& what_to_show, int use_rth, int format_date);

  // 请求市场数据的类型
  static void BuildMsgReqMarketDataType(ostringstream& oss, int market_data_type);

  // 请求账户更新
  static void BuildMsgReqAccountUpdates(ostringstream& oss, bool subscribe, string acct_code);
};

}

#endif //TWS_MESSAGE_BUILDER_SOCKET_H_
