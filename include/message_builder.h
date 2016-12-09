#ifndef TWS_MESSAGE_BUILDER_SOCKET_H_
#define TWS_MESSAGE_BUILDER_SOCKET_H_

#include <sstream>

using std::ostringstream;

namespace tws_shell {

class MessageBuilder {

public:
  static void BuildMsgClientVersion(ostringstream& oss);
  static void BuildMsgStartApi(ostringstream& oss);

};

}

#endif //TWS_MESSAGE_BUILDER_SOCKET_H_
