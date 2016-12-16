#ifndef TWS_SHELL_CONFIG_H_
#define TWS_SHELL_CONFIG_H_

#include <string>
#include <vector>

#include "singleton.h"

using std::string;
using std::vector;

namespace tws_shell {

class Config {

public:
  int Init();

  const vector<string>& get_watch_list() const;
  string get_host() const;
  int get_port() const;

private:
  Config() : host_("127.0.0.1"), port_(4001) {}
  int Load();

private:
  vector<string>  watch_list_;
  string          host_;
  int             port_;

  friend class Singleton<Config>;
};

inline const vector<string>& Config::get_watch_list() const {
  return watch_list_;
}

inline string Config::get_host() const {
  return host_;
}

inline int Config::get_port() const {
  return port_;
}

} // namespace tws_shell

#endif //TWS_SHELL_CONFIG_H_
