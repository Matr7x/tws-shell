#include "parameter_manager.h"

#include "tick_info.h"

namespace tws_shell {

void ParameterManager::CreateTick(int ticker_id, string symbol) {
  TickInfo tick;
  tick.symbol = symbol;
  ticker_info_map_[ticker_id] = tick;
}

} // namespece tws_shell
