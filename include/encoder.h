#ifndef TWS_SHELL_ENCODER_H_
#define TWS_SHELL_ENCODER_H_

#include <iostream>
#include <sstream>
#include <iomanip>

namespace tws_shell {

// Declaration

template<class T>
class Encoder {

public:
  static void Encode(std::ostream& os, T value);

private:
  static const char kZero;

};

// Implementation

template<class T>
const char Encoder<T>::kZero = '\0';

// 通用编码函数
template<class T>
void Encoder<T>::Encode(std::ostream& os, T value) {
  os << value << kZero;
}

// bool编码
template<>
void Encoder<bool>::Encode(std::ostream& os, bool value) {
  Encoder<int>::Encode(os, value ? 1 : 0);
}

// double编码
template<>
void Encoder<double>::Encode(std::ostream& os, double value) {
  os << std::setprecision(8) << value << kZero;
}

} // namespace tws_shell

#endif//TWS_SHELL_ENCODER_H_

