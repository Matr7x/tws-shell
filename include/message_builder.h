#ifndef TWS_MESSAGE_BUILDER_SOCKET_H_
#define TWS_MESSAGE_BUILDER_SOCKET_H_

#include <sstream>

#include "contract.h"

using std::ostringstream;

namespace tws_shell {

class MessageBuilder {

public:
  static void BuildMsgClientVersion(ostringstream& oss);
  static void BuildMsgStartApi(ostringstream& oss);
  static void BuildMsgReqContractDetails(ostringstream& oss, int req_id, Contract& contract);
  static void BuildMsgReqMktData(ostringstream& oss, int ticker_id, Contract& contract, string generic_ticks, bool snapshot);
  static void BuildMsgReqAccountSummary(ostringstream& oss, int req_id, const string& group_name, const string& tags);
  static void BuildMsgReqPositions(ostringstream& oss);
  static void BuildMsgReqHistoricalData(ostringstream& oss, long ticker_id, const Contract& contract, const string& end_date_time, const string& duration, const string& bar_size, const string& what_to_show, int use_rth, int format_date);

};

}

#endif //TWS_MESSAGE_BUILDER_SOCKET_H_
