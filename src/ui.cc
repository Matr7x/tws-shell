#include "ui.h"

#include <iostream>

#include "parameter_manager.h"

using std::cout;
using std::cerr;
using std::endl;

namespace tws_shell {

string WATCH_TITLE[] = {
  "SYMBOL", "BID_SIZE", "BID_PRICE", "ASK_PRICE", "ASK_SIZE", "LAST_PRICE", "PERCENT",
  "LAST_SIZE", "HIGH_PRICE", "LOW_PRICE", "OPEN_PRICE", "CLOSE_PRICE", "VOLUME"
};

int WATCH_COLUMN_SIZE[] = {
  10, 10, 10, 10, 10, 10, 10,
  10, 10, 10, 10, 11, 10
};

int UI::Init() {
  main_window_ = initscr();
  if (NULL == main_window_) {
    cerr << "Init ncurses failed." << endl;
    return 255;
  }

  start_color();

  if (has_colors()) {
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_BLACK);
    init_pair(8, COLOR_GREEN, COLOR_BLACK);
    init_pair(9, COLOR_RED, COLOR_BLACK);
  }
  
  //color_set(1, NULL);
  //mvaddstr(0, 0, "tws-shell");
  DisplayWatchTitle();
  DisplayWatchList();

  return 0;
}

void UI::DisplayWatchTitle() {
  int column_num = sizeof(WATCH_TITLE) / sizeof(WATCH_TITLE[0]);
  int pos = 0;
  for (int i = 0; i < column_num; i++) {
    color_set(6, NULL);
    mvaddstr(0, pos, AlignStr(WATCH_TITLE[i], WATCH_COLUMN_SIZE[i]).c_str());
    pos += WATCH_COLUMN_SIZE[i];
    color_set(6, NULL);
    mvaddstr(0, pos, " ");
    pos++;
  }
  pos = 0;
  for (int i = 0; i < column_num; i++) {
    color_set(1, NULL);
    for (int j = 0; j < WATCH_COLUMN_SIZE[i]; j++) {
      mvaddstr(1, pos, "=");
      pos++;
    }
    if (column_num != i + 1) {
      mvaddstr(1, pos, "|");
    }
    pos++;
  }
  refresh();
}

void UI::DisplayWatchList() {
  ParameterManager* pm = Singleton<ParameterManager>::GetInstance();
  map<int, TickInfo> ticker_info_map = pm->get_ticker_info_map();

  int line = 2;

  for (auto item : ticker_info_map) {
    TickInfo ti = item.second;

    vector<string> columns = ti.GetList();

    int pos = 0;
    for (size_t i = 0; i < columns.size(); i++) {
      symbol_line_map_[ti.symbol] = line;
      if (0 == line % 2) {
        color_set(1, NULL);
      } else {
        color_set(7, NULL);
      }
      mvaddstr(line, pos, AlignStr(columns[i], WATCH_COLUMN_SIZE[i]).c_str());
      pos += WATCH_COLUMN_SIZE[i];
      color_set(1, NULL);
      if (columns.size() != i + 1) {
        mvaddstr(line, pos, "|");
      }
      pos++;
    }

    line++;
  }
  refresh();
}

void UI::RefreshWatchListColumn(string symbol, WatchColumn column, string value) {
  int line = symbol_line_map_[symbol];
  int pos = 0;
  int j = 0;

  for (int i = 0; i < (int)column; i++) {
    pos += WATCH_COLUMN_SIZE[i];
    pos++;
    j++;
  }

  if (kPercent == column && '-' == value[0]) {
    if (0 == line % 2) {
      color_set(5, NULL);
    } else {
      color_set(9, NULL);
    }
  } else if(kPercent == column) {
    if (0 == line % 2) {
      color_set(4, NULL);
    } else {
      color_set(8, NULL);
    }
  } else {
    if (0 == line % 2) {
      color_set(1, NULL);
    } else {
      color_set(7, NULL);
    }
  }
  //mvaddstr(30, 0, value.c_str());
  mvaddstr(line, pos, AlignStr(value, WATCH_COLUMN_SIZE[j]).c_str());
  refresh();
}

string UI::AlignStr(string str, int size) {
  string s = str;
  int len = s.length();
  if (len > size) {
    return " " + s.substr(0, size - 1);
  } else if(len < size) {
    for (int i = 0; i < (size - len - 1); i++) {
      s += " ";
    }
    return " " + s;
  } else {
    return s;
  }
}

} // namespace tws_shell
