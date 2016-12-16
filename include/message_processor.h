#ifndef TWS_MESSAGE_PROCESSOR_SOCKET_H_
#define TWS_MESSAGE_PROCESSOR_SOCKET_H_

#include "event_wrapper.h"

namespace tws_shell {
class MessageProcessor {
public:
  MessageProcessor(EventWrapper* wrapper) : wrapper_(wrapper) {}

public:
  int ProcessManagedAccts(char* buf, int size);
  int ProcessNextValidId(char* buf, int size);
  int ProcessErrMsg(char* buf, int size);
  int ProcessContractData(char* buf, int size);
  int ProcessContractDataEnd(char* buf, int size);
  int ProcessTickString(char* buf, int size);
  int ProcessTickPrice(char* buf, int size);
  int ProcessTickSize(char* buf, int size);
  int ProcessAccountSummary(char* buf, int size);
  int ProcessAccountSummaryEnd(char* buf, int size);
  int ProcessPositionData(char* buf, int size);
  int ProcessPositionEnd(char* buf, int size);
  int ProcessHistoricalData(char* buf, int size);
  int ProcessAcctValue(char* buf, int size);
  int ProcessAcctUpdateTime(char* buf, int size);
  int ProcessPortfolioValue(char* buf, int size);
  int ProcessAcctDownloadEnd(char* buf, int size);
  int ProcessTickGeneric(char* buf, int size);

private:
  MessageProcessor() {}

private:
  EventWrapper* wrapper_;

};
} // namespace tws_shell

#endif //TWS_MESSAGE_PROCESSOR_SOCKET_H_
