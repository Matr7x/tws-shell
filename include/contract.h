#ifndef TWS_SHELL_CONTRACT_H_
#define TWS_SHELL_CONTRACT_H_

#include <string>

using std::string;

namespace tws_shell {

struct Contract {
  Contract() : con_id(0), strike(0.0), include_expired(false) {}

  long con_id;
  string symbol;
  string sec_type;
  string expiry;
  double strike;
  string right;
  string multiplier;
  string exchange;
  string primary_exchange;
  string currency;
  string local_symbol;
  string trading_class;
  bool include_expired;
  string sec_id_type;
  string sec_id;
};

} // namespace tws_shell

#endif //TWS_SHELL_CONTRACT_H_
