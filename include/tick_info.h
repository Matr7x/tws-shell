#ifndef TWS_SHELL_TICK_INFO_H_
#define TWS_SHELL_TICK_INFO_H_

#include <math.h>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::ostringstream;

namespace tws_shell {

struct TickInfo {
  TickInfo() : bid_price(NAN), ask_price(NAN), last_price(NAN), high(NAN), low(NAN),
    close_price(NAN), open_price(NAN), bid_size(-1), ask_size(-1), last_size(-1),
    volume(-1), last_timestamp(0) {}

  vector<string> GetList();

  string symbol;
  
  double bid_price;
  double ask_price;
  double last_price;
  double high;
  double low;
  double close_price;
  double open_price;

  int bid_size;
  int ask_size;
  int last_size;
  int volume;
  int last_timestamp;
};

inline vector<string> TickInfo::GetList() {
  vector<string> list;

  ostringstream oss;

  oss << symbol;
  list.push_back(oss.str());

  oss.str("");
  oss << bid_size;
  list.push_back(oss.str());

  oss.str("");
  oss << bid_price;
  list.push_back(oss.str());

  oss.str("");
  oss << ask_price;
  list.push_back(oss.str());

  oss.str("");
  oss << ask_size;
  list.push_back(oss.str());

  oss.str("");
  oss << last_price;
  list.push_back(oss.str());

  if (isnan(last_price) || isnan(close_price)) {
    list.push_back("nan");
  } else {
    oss.str("");
    oss << (last_price - close_price) / close_price;
    list.push_back(oss.str());
  }

  oss.str("");
  oss << last_size;
  list.push_back(oss.str());

  oss.str("");
  oss << high;
  list.push_back(oss.str());

  oss.str("");
  oss << low;
  list.push_back(oss.str());

  oss.str("");
  oss << open_price;
  list.push_back(oss.str());

  oss.str("");
  oss << close_price;
  list.push_back(oss.str());

  oss.str("");
  oss << volume;
  list.push_back(oss.str());

  return list;
}

} // namespace tws_shell

#endif //TWS_SHELL_TICK_INFO_H_
