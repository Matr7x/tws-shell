#ifndef TWS_SHELL_ENCODER_H_
#define TWS_SHELL_ENCODER_H_

#include <iostream>
#include <sstream>
#include <iomanip>

namespace tws_shell {

// Declaration

class Encoder {

public:
  template<class T>
  static void Encode(std::ostream& os, T value);

private:
  static const char kZero;

};

// Implementation

// 通用编码函数
template<class T>
void Encoder::Encode(std::ostream& os, T value) {
  os << value << kZero;
}

} // namespace tws_shell

#endif//TWS_SHELL_ENCODER_H_

