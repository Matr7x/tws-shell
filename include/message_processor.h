#ifndef TWS_MESSAGE_PROCESSOR_SOCKET_H_
#define TWS_MESSAGE_PROCESSOR_SOCKET_H_

namespace tws_shell {
class MessageProcessor {

public:
  static int ProcessManagedAccts(char* buf, int size);
  static int ProcessNextValidId(char* buf, int size);
  static int ProcessErrMsg(char* buf, int size);
  static int ProcessContractData(char* buf, int size);
  static int ProcessContractDataEnd(char* buf, int size);
  static int ProcessTickString(char* buf, int size);
  static int ProcessTickPrice(char* buf, int size);
  static int ProcessTickSize(char* buf, int size);
  static int ProcessAccountSummary(char* buf, int size);
  static int ProcessAccountSummaryEnd(char* buf, int size);
  static int ProcessPositionData(char* buf, int size);
  static int ProcessPositionEnd(char* buf, int size);
  static int ProcessHistoricalData(char* buf, int size);
};
} // namespace tws_shell

#endif //TWS_MESSAGE_PROCESSOR_SOCKET_H_
