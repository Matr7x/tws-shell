#ifndef TWS_SHELL_PARAMETER_MANAGER_H_
#define TWS_SHELL_PARAMETER_MANAGER_H_

#include <map>
#include <string>

#include "singleton.h"
#include "tick_info.h"

using std::map;
using std::string;

namespace tws_shell {

class ParameterManager {
public:
  void CreateTick(int ticker_id, string symbol);

  void set_account(string account);
  void set_next_valid_order_id(int id);

  int get_next_ticker_id();
  TickInfo& get_tick_info(int ticker_id); 
  map<int, TickInfo> get_ticker_info_map();

private:
  ParameterManager() : next_valid_order_id_(0), next_ticker_id_(0) {}

private:
  map<int, TickInfo> ticker_info_map_;
  string account_;
  int next_valid_order_id_;
  int next_ticker_id_;

  friend class Singleton<ParameterManager>;
};

inline void ParameterManager::set_account(string account) {
  account_ = account;
}

inline void ParameterManager::set_next_valid_order_id(int id) {
  next_valid_order_id_ = id;
}

inline int ParameterManager::get_next_ticker_id() {
  return next_ticker_id_++;
}

inline TickInfo& ParameterManager::get_tick_info(int ticker_id) {
  return ticker_info_map_[ticker_id];
}

inline map<int, TickInfo> ParameterManager::get_ticker_info_map() {
  return ticker_info_map_;
}

}

#endif //TWS_SHELL_PARAMETER_MANAGER_H_
