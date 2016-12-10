#ifndef TWS_SHELL_DECODER_H_
#define TWS_SHELL_DECODER_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

namespace tws_shell {

class Decoder {

public:
  static int Decode(char* ptr, int size, int& value);
  static int Decode(char* ptr, int size, long& value);
  static int Decode(char* ptr, int size, bool& value);
  static int Decode(char* ptr, int size, double& value);
  static int Decode(char* ptr, int size, string& value);

private:
  static const char* FindZero(char*& ptr, int size);

};

} // namespace tws_shell

#endif//TWS_SHELL_DECODER_H_
