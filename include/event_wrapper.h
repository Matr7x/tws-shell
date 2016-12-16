#ifndef TWS_SHELL_EVENT_WRAPPER_H_
#define TWS_SHELL_EVENT_WRAPPER_H_

#include <string>

using std::string;

namespace tws_shell {

class EventWrapper {
public:
  ~EventWrapper() {}

public:
  virtual void OnEventManagedAccounts(const string& account_list) = 0;
  virtual void OnEventNextValidId(const int& next_valid_id) = 0;
  virtual void OnEventTickPrice(const int& ticker_id, const int& tick_type, const double& price, const int& can_auto_execute) = 0;
  virtual void OnEventTickSize(const int& ticker_id, const int& tick_type, const int& size) = 0;
  virtual void OnEventTickString(const int& ticker_id, const int& tick_type, const string& value) = 0;
  /*virtual void OnEventErrMsg(const int& id, const int& err_code, const string& err_msg) = 0;*/
  ///*virtual void OnEventContractData(const int& req_id*//*, TODO*/) = 0;

};

} // namespace tws_shell

#endif //TWS_SHELL_EVENT_WRAPPER_H_
