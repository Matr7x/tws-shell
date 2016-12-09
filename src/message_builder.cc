#include "message_builder.h"

#include "defines.h"
#include "encoder.h"

namespace tws_shell {

void MessageBuilder::BuildMsgClientVersion(ostringstream& oss) {
  Encoder<int>::Encode(oss, kClientVersion);
}

void MessageBuilder::BuildMsgStartApi(ostringstream& oss) {
  const int kVersion = 1;
  Encoder<int>::Encode(oss, kMsgIdStartApi);
  Encoder<int>::Encode(oss, kVersion);
  Encoder<int>::Encode(oss, kClientId);
}

} // namespace tws_shell
