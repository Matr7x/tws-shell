#include "config.h"

#include <iostream>

#include "cpptoml.h"

using std::cout;
using std::endl;

namespace tws_shell {

int Config::Init() {
  if (0 != Load()) {
    cout << "Init config failed." << endl;
    exit(255);
  }
  return 0;
}

int Config::Load() {
  try  {
    // Get Home Path
    string home = getenv("HOME");

    // Parse tws-shell config.
    std::shared_ptr<cpptoml::table> g = cpptoml::parse_file(home + "/.tws-shell/config.toml");

    // Get host and port
    host_ = g->get_as<string>("host").value_or("127.0.0.1");
    port_ = g->get_as<int>("port").value_or(4001);

    // Get watch list
    auto watch_list = g->get_array_of<string>("watch_list");
    for (const auto& item : *watch_list) {
      watch_list_.push_back(item);
    }
  } catch (const cpptoml::parse_exception& e) {
    cout << "No config loaded!" << endl;
  }
  return 0;
}

} // namespace tws_shell
