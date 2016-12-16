#include "message_builder.h"

#include "defines.h"
#include "encoder.h"
#include "contract.h"

namespace tws_shell {

void MessageBuilder::BuildMsgClientVersion(ostringstream& oss) {
  ENCODE(kClientVersion);
}

void MessageBuilder::BuildMsgStartApi(ostringstream& oss) {
  const int kVersion = 1;
  ENCODE(kMsgIdStartApi);
  ENCODE(kVersion);
  ENCODE(kClientId);
}

void MessageBuilder::BuildMsgReqContractDetails(ostringstream& oss, int req_id, Contract& contract) {
  const int kVersion = 7;
  ENCODE(kMsgIdReqContractData);
  ENCODE(kVersion);
  ENCODE(req_id);
  ENCODE(contract.con_id);
  ENCODE(contract.symbol);
  ENCODE(contract.sec_type);
  ENCODE(contract.expiry);
  ENCODE(contract.strike);
  ENCODE(contract.right);
  ENCODE(contract.multiplier);
  ENCODE(contract.exchange);
  ENCODE(contract.currency);
  ENCODE(contract.local_symbol);
  ENCODE(contract.trading_class);
  ENCODE(contract.include_expired);
  ENCODE(contract.sec_id_type);
  ENCODE(contract.sec_id);
}

void MessageBuilder::BuildMsgReqMktData(ostringstream& oss, int ticker_id, Contract& contract, string generic_ticks, bool snapshot) {
  const int kVersion = 11;
  ENCODE(kMsgIdReqMktData);
  ENCODE(kVersion);
  ENCODE(ticker_id);
  ENCODE(contract.con_id);
  ENCODE(contract.symbol);
  ENCODE(contract.sec_type);
  ENCODE(contract.expiry);
  ENCODE(contract.strike);
  ENCODE(contract.right);
  ENCODE(contract.multiplier);
  ENCODE(contract.exchange);
  ENCODE(contract.primary_exchange);
  ENCODE(contract.currency);
  ENCODE(contract.local_symbol);
  ENCODE(contract.trading_class);
  ENCODE(false);
  ENCODE(generic_ticks);
  ENCODE(snapshot);
  ENCODE("");
}

void MessageBuilder::BuildMsgReqAccountSummary(ostringstream& oss, int req_id, const string& group_name, const string& tags) {
  const int kVersion = 1;
  ENCODE(kMsgIdReqAccountSummary);
  ENCODE(kVersion);
  ENCODE(req_id);
  ENCODE(group_name);
  ENCODE(tags);
}

void MessageBuilder::BuildMsgReqPositions(ostringstream& oss) {
  const int kVersion = 1;
  ENCODE(kMsgIdReqPositions);
  ENCODE(kVersion);
}

void MessageBuilder::BuildMsgReqHistoricalData(ostringstream& oss, long ticker_id, const Contract& contract, const string& end_date_time, const string& duration, const string& bar_size, const string& what_to_show, int use_rth, int format_date) {
  const int kVersion = 6;
  ENCODE(kMsgIdReqHistoricalData);
  ENCODE(kVersion);
  ENCODE(ticker_id);
  ENCODE(contract.con_id);
  ENCODE(contract.symbol);
  ENCODE(contract.sec_type);
  ENCODE(contract.expiry);
  ENCODE(contract.strike);
  ENCODE(contract.right);
  ENCODE(contract.multiplier);
  ENCODE(contract.exchange);
  ENCODE(contract.primary_exchange);
  ENCODE(contract.currency);
  ENCODE(contract.local_symbol);
  ENCODE(contract.trading_class);
  ENCODE(contract.include_expired);
  ENCODE(end_date_time);
  ENCODE(bar_size);
  ENCODE(duration);
  ENCODE(use_rth);
  ENCODE(what_to_show);
  ENCODE(format_date);
  ENCODE("");
}

void MessageBuilder::BuildMsgReqMarketDataType(ostringstream& oss, int market_data_type) {
  const int kVersion = 1;
  ENCODE(kMsgIdReqMarketDataType);
  ENCODE(kVersion);
  ENCODE(market_data_type);
}

void MessageBuilder::BuildMsgReqAccountUpdates(ostringstream& oss, bool subscribe, string acct_code) {
  const int kVersion = 2;
  ENCODE(kMsgIdReqAccountUpdates);
  ENCODE(kVersion);
  ENCODE(subscribe);
  ENCODE(acct_code);
}

} // namespace tws_shell
