#include "contract.h"

namespace tws_shell {

Contract Contract::CreateStock(string symbol) {
  Contract c;
  c.symbol = symbol;
  c.sec_type = "STK";
  c.exchange = "SMART";
  c.currency = "USD";

  return c;
}

} // namespace tws_shell
