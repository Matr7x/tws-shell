#include "event_handler.h"

#include <iostream>
#include <iomanip>

#include "ui.h"
#include "singleton.h"
#include "parameter_manager.h"

using std::cout;
using std::endl;
using std::ios;
using std::setprecision;

namespace tws_shell {

void EventHandler::OnEventManagedAccounts(const string& account_list) {
  // TODO: Here I have only one account
  Singleton<ParameterManager>::GetInstance()->set_account(account_list);
}
void EventHandler::OnEventNextValidId(const int& next_valid_id) {
  Singleton<ParameterManager>::GetInstance()->set_next_valid_order_id(next_valid_id);
}
void EventHandler::OnEventTickPrice(const int& ticker_id, const int& tick_type, const double& price, const int& can_auto_execute) {
  TickInfo& ti = Singleton<ParameterManager>::GetInstance()->get_tick_info(ticker_id);
  UI* ui = Singleton<UI>::GetInstance();

  ostringstream oss;
  oss << price;

  switch(tick_type) {
    case 1: {
      ti.bid_price = price;
      ui->RefreshWatchListColumn(ti.symbol, kBidPrice, oss.str());
      break;
    }
    case 2: {
      ti.ask_price = price;
      ui->RefreshWatchListColumn(ti.symbol, kAskPrice, oss.str());
      break;
    }
    case 4: {
      ti.last_price = price;
      ui->RefreshWatchListColumn(ti.symbol, kLastPrice, oss.str());

      if (!isnan(ti.last_price) && !isnan(ti.close_price)) {
        ostringstream oss2;
        oss2.setf(ios::fixed);
        oss2 << setprecision(2) << (ti.last_price - ti.close_price) / ti.close_price * 100 << "%";
        cout.unsetf(ios::fixed);
        ui->RefreshWatchListColumn(ti.symbol, kPercent, oss2.str());
      }
      break;
    }
    case 6: {
      ti.high = price;
      ui->RefreshWatchListColumn(ti.symbol, kHigh, oss.str());
      break;
    }
    case 7: {
      ti.low = price;
      ui->RefreshWatchListColumn(ti.symbol, kLow, oss.str());
      break;
    }
    case 9: {
      ti.close_price = price;
      ui->RefreshWatchListColumn(ti.symbol, kClosePrice, oss.str());

      if (!isnan(ti.last_price) && !isnan(ti.close_price)) {
        ostringstream oss2;
        oss2.setf(ios::fixed);
        oss2 << setprecision(2) << (ti.last_price - ti.close_price) / ti.close_price * 100 << "%";
        cout.unsetf(ios::fixed);
        ui->RefreshWatchListColumn(ti.symbol, kPercent, oss2.str());
      }
      break;
    }
    case 14: {
      ti.open_price = price;
      ui->RefreshWatchListColumn(ti.symbol, kOpenPrice, oss.str());
      break;
    }
  }

  
  //cout << ti.symbol << ", " << ti.last_timestamp<< ", " << ti.ask_price << ", " << ti.bid_price << ", " << ti.ask_size << ", " 
    //<< ti.bid_size << ", " << ti.volume << ", " << ti.last_price << ", " << ti.last_size  << ", " << ti.high << ", " 
    //<< ti.low << ", " << ti.close_price << ", " << ti.open_price << endl;
}

void EventHandler::OnEventTickSize(const int& ticker_id, const int& tick_type, const int& size) {

  TickInfo& ti = Singleton<ParameterManager>::GetInstance()->get_tick_info(ticker_id);
  UI* ui = Singleton<UI>::GetInstance();

  ostringstream oss;
  oss << size;

  switch(tick_type) {
    case 0:
      ti.bid_size = size;
      ui->RefreshWatchListColumn(ti.symbol, kBidSize, oss.str());
      break;
    case 3:
      ti.ask_size = size;
      ui->RefreshWatchListColumn(ti.symbol, kAskSize, oss.str());
      break;
    case 5:
      ti.last_size = size;
      ui->RefreshWatchListColumn(ti.symbol, kLastSize, oss.str());
      break;
    case 8:
      ti.volume = size;
      ui->RefreshWatchListColumn(ti.symbol, kVolume, oss.str());
      break;
  }

  //cout << ti.symbol << ", " << ti.last_timestamp<< ", " << ti.ask_price << ", " << ti.bid_price << ", " << ti.ask_size << ", " 
    //<< ti.bid_size << ", " << ti.volume << ", " << ti.last_price << ", " << ti.last_size  << ", " << ti.high << ", " 
    //<< ti.low << ", " << ti.close_price << ", " << ti.open_price << endl;
}

void EventHandler::OnEventTickString(const int& ticker_id, const int& tick_type, const string& value) {
  TickInfo& ti = Singleton<ParameterManager>::GetInstance()->get_tick_info(ticker_id);
  //UI* ui = Singleton<UI>::GetInstance();

  //ostringstream oss;
  //oss << value;

  switch(tick_type) {
    case 45:
      ti.last_timestamp = atoi(value.c_str());
      //ui->RefreshWatchListColumn(ti.symbol, kTimestamp, oss.str());
      break;
  }

  //cout << ti.symbol << ", " << ti.last_timestamp<< ", " << ti.ask_price << ", " << ti.bid_price << ", " << ti.ask_size << ", " 
    //<< ti.bid_size << ", " << ti.volume << ", " << ti.last_price << ", " << ti.last_size  << ", " << ti.high << ", " 
    //<< ti.low << ", " << ti.close_price << ", " << ti.open_price << endl;
}

} // namespace tws_shell
