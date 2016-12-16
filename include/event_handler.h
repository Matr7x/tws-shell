#ifndef TWS_SHELL_EVENT_HANDLER_H_
#define TWS_SHELL_EVENT_HANDLER_H_

#include <string>

#include "event_wrapper.h"

using std::string;

namespace tws_shell {

class EventHandler : public EventWrapper {
public:
  EventHandler() {}
  ~EventHandler() {}

public:
  virtual void OnEventManagedAccounts(const string& accoutn_list);
  virtual void OnEventNextValidId(const int& next_valid_id);
  virtual void OnEventTickPrice(const int& ticker_id, const int& tick_type, const double& price, const int& can_auto_execute);
  virtual void OnEventTickSize(const int& ticker_id, const int& tick_type, const int& size);
  virtual void OnEventTickString(const int& ticker_id, const int& tick_type, const string& value);

};

} // namespace tws_shell

#endif //TWS_SHELL_EVENT_HANDLER_H_
