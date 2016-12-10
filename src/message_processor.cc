#include "message_processor.h"

#include <iostream>

#include "decoder.h"
#include "defines.h"
#include "contract.h"

namespace tws_shell {

int MessageProcessor::ProcessManagedAccts(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Managed Accts ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  string account_list;

  DECODE(version);
  DECODE(account_list);

  cout << "Version: " << version << endl;
  cout << "Account List: " << account_list << endl;

  cout << "[End] ### Process Managed Accts ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessNextValidId(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Next Valid Id ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  int order_id;

  DECODE(version);
  DECODE(order_id);

  cout << "Version: " << version << endl;
  cout << "Next Order Id: " << order_id << endl;

  cout << "[End] ### Process Next Valid Id ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessErrMsg(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Error Msg ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  int id;
  int err_code;
  string err_msg;

  DECODE(version);
  DECODE(id);
  DECODE(err_code);
  DECODE(err_msg);

  cout << "Version: " << version << endl;
  cout << "Id: " << id << endl;
  cout << "Error Code: " << err_code << endl;
  cout << "Error Msg: " << err_msg << endl;

  cout << "[End] ### Process Error Msg ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessContractData(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Contract Data ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  int req_id;
  string symbol;
  string sec_type;
  string expiry;
  string strike;
  string right;
  string exchange;
  string currency;
  string local_symbol;
  string market_name;
  string trading_class;
  long con_id;
  double min_tick;
  string multiplier;
  string order_types;
  string valid_exchange;
  string price_magnifier;
  string under_con_id;
  string long_name;
  string primary_exchange;
  string contract_month;
  string industry;
  string category;
  string sub_category;
  string time_zone_id;
  string trading_hours;
  string liquid_hours;
  string ev_rule;
  string ev_multiplier;
  string sec_id_list_count;

  DECODE(version);
  DECODE(req_id);
  DECODE(symbol);
  DECODE(sec_type);
  DECODE(expiry);
  DECODE(strike);
  DECODE(right);
  DECODE(exchange);
  DECODE(currency);
  DECODE(local_symbol);
  DECODE(market_name);
  DECODE(trading_class);
  DECODE(con_id);
  DECODE(min_tick);
  DECODE(multiplier);
  DECODE(order_types);
  DECODE(valid_exchange);
  DECODE(price_magnifier);

  if (version >= 4) {
    DECODE(under_con_id);
  }

  if (version >= 5) {
    DECODE(long_name);
    DECODE(primary_exchange);
  }

  if (version >= 6) {
    DECODE(contract_month);
    DECODE(industry);
    DECODE(category);
    DECODE(sub_category);
    DECODE(time_zone_id);
    DECODE(trading_hours);
    DECODE(liquid_hours);
  }

  if (version >= 8) {
    DECODE(ev_rule);
    DECODE(ev_multiplier);
  }

  if (version >= 7) {
    DECODE(sec_id_list_count);
    // TODO: read sec id list
  }

  cout << "Version: " << version << endl;
  cout << "req_id: " << req_id << endl;
  cout << "symbol: " << symbol << endl;
  cout << "sec_type: " << sec_type << endl;
  cout << "expiry: " << expiry << endl;
  cout << "right: " << right << endl;
  cout << "exchange: " << exchange << endl;
  cout << "currency: " << currency << endl;
  cout << "local symbol: " << local_symbol << endl;
  cout << "market name: " << market_name << endl;
  cout << "trading class: " << trading_class << endl;
  cout << "con_id: " << con_id << endl;
  cout << "min_tick: " << min_tick << endl;
  cout << "multiplier: " << multiplier << endl;
  cout << "order_types: " << order_types << endl;
  cout << "valid_exchange: " << valid_exchange << endl;
  cout << "price_magnifier: " << price_magnifier << endl;
  cout << "under_con_id: " << under_con_id << endl;
  cout << "long_name: " << long_name << endl;
  cout << "primary_exchange: " << primary_exchange << endl;
  cout << "contract_month: " << contract_month << endl;
  cout << "industry: " << industry << endl;
  cout << "category: " << category << endl;
  cout << "time_zone_id: " << time_zone_id << endl;
  cout << "trading_hours: " << trading_hours << endl;
  cout << "liquid_hours: " << liquid_hours << endl;
  cout << "ev_rule: " << ev_rule << endl;
  cout << "ev_multiplier: " << ev_multiplier << endl;
  cout << "sec_id_list_count: " << sec_id_list_count << endl;

  cout << "[End] ### Process Contract Data ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessContractDataEnd(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Contract Data End ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  int req_id;

  DECODE(version);
  DECODE(req_id);

  cout << "Version: " << version << endl;
  cout << "req_id: " << req_id << endl;

  cout << "[End] ### Process Contract Data End ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessTickString(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Tick String ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  long ticker_id;
  int ticker_type_int;
  string value;

  DECODE(version);
  DECODE(ticker_id);
  DECODE(ticker_type_int);
  DECODE(value);

  cout << "Version: " << version << endl;
  cout << "Ticker id: " << ticker_id << endl;
  cout << "Ticker type int: " << ticker_type_int << endl;
  cout << "Value: " << value << endl;

  cout << "[End] ### Process Tick String ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessTickPrice(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Tick Price ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  long ticker_id;
  int ticker_type_int;
  double price;
  int size2;
  int can_auto_execute;

  DECODE(version);
  DECODE(ticker_id);
  DECODE(ticker_type_int);
  DECODE(price);
  DECODE(size2);
  DECODE(can_auto_execute);

  cout << "Version: " << version << endl;
  cout << "Ticker id: " << ticker_id << endl;
  cout << "Ticker type int: " << ticker_type_int << endl;
  cout << "Price: " << price << endl;
  cout << "Size: " << size2 << endl;
  cout << "Can auto execute: " << can_auto_execute<< endl;

  cout << "[End] ### Process Tick Price ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessTickSize(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Tick Size ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  long ticker_id;
  int ticker_type_int;
  string size2;

  DECODE(version);
  DECODE(ticker_id);
  DECODE(ticker_type_int);
  DECODE(size2);
  
  cout << "Version: " << version << endl;
  cout << "Ticker id: " << ticker_id << endl;
  cout << "Ticker type int: " << ticker_type_int << endl;
  cout << "Size: " << size2 << endl;

  cout << "[End] ### Process Tick Size ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessAccountSummary(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Account Summary End ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  long req_id;
  string account;
  string tag;
  string value;
  string currency;

  DECODE(version);
  DECODE(req_id);
  DECODE(account);
  DECODE(tag);
  DECODE(value);
  DECODE(currency);
  
  cout << "Version: " << version << endl;
  cout << "Req id: " << req_id << endl;
  cout << "Account: " << account << endl;
  cout << "Tag: " << tag << endl;
  cout << "Value: " << value << endl;
  cout << "Currency: " << currency << endl;

  cout << "[End] ### Process Account Summary End ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessAccountSummaryEnd(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Account Summary ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  long req_id;

  DECODE(version);
  DECODE(req_id);
  
  cout << "Version: " << version << endl;
  cout << "Req id: " << req_id << endl;

  cout << "[End] ### Process Account Summary ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessPositionData(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Position Data ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  string account;
  int position;
  double avg_cost = 0.0;
  Contract contract;

  DECODE(version);
  DECODE(account);
  DECODE(contract.con_id);
  DECODE(contract.symbol);
  DECODE(contract.sec_type);
  DECODE(contract.expiry);
  DECODE(contract.strike);
  DECODE(contract.right);
  DECODE(contract.multiplier);
  DECODE(contract.exchange);
  DECODE(contract.currency);
  DECODE(contract.local_symbol);

  if (version >= 2) {
    DECODE(contract.trading_class);
  }
  DECODE(position);
  if (version >= 3) {
    DECODE(avg_cost);
  }
  
  cout << "Version: " << version << endl;
  cout << "Account: " << account << endl;
  cout << "Con id: " << contract.con_id<< endl;
  cout << "Symbol: " << contract.symbol << endl;
  cout << "Sec type: " << contract.sec_type << endl;
  cout << "Expiry: " << contract.expiry << endl;
  cout << "Strike: " << contract.strike << endl;
  cout << "Right: " << contract.right << endl;
  cout << "Multiplier: " << contract.multiplier << endl;
  cout << "Exchange: " << contract.exchange << endl;
  cout << "Currency: " << contract.currency << endl;
  cout << "Local Symbol: " << contract.local_symbol << endl;
  cout << "Trading Class: " << contract.trading_class << endl;
  cout << "Position: " << position << endl;
  cout << "Avg cost: " << avg_cost << endl;

  cout << "[End] ### Process Position Data ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessPositionEnd(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Position End ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;

  DECODE(version);

  cout << "Version: " << version << endl;

  cout << "[End] ### Process Position End ###" << endl << endl;
  return processed;
}

int MessageProcessor::ProcessHistoricalData(char* buf, int size) {
  cout << endl;
  cout << "[Begin] ### Process Historical Data ###" << endl;

  int processed = 0;
  int decoded = 0;

  int version = 0;
  int req_id = 0;
  string start_date;
  string end_date;

  DECODE(version);
  DECODE(req_id);
  DECODE(start_date);
  DECODE(end_date);

  cout << "Version: " << version << endl;
  cout << "Req id: " << req_id << endl;
  cout << "Start Date: " << start_date << endl;
  //cout << "End Date: " << end_date << endl;

  cout << "[End] ### Process Historical Data ###" << endl << endl;
  return processed;
}

} // namespace tws_shell
