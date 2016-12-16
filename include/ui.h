#ifndef TWS_SHELL_UI_H_
#define TWS_SHELL_UI_H_

#include <map>
#include <string>
#include <curses.h>

#include "singleton.h"

using std::map;
using std::string;

namespace tws_shell {

enum WatchColumn {
  kSymbol,
  kBidSize,
  kBidPrice,
  kAskPrice,
  kAskSize,
  kLastPrice,
  kPercent,
  kLastSize,
  kHigh,
  kLow,
  kOpenPrice,
  kClosePrice,
  kVolume
};

class UI {

public:
  int Init();
  void DisplayWatchTitle();
  void DisplayWatchList();
  void RefreshWatchListColumn(string symbol, WatchColumn column, string value);

private:
  UI() {}

private:
  string AlignStr(string str, int size);

private:
  WINDOW * main_window_;
  map<string, int> symbol_line_map_;

  friend class Singleton<UI>;

};

} // namespace tws_shell

#endif //TWS_SHELL_UI_H_
