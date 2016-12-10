#include "encoder.h"

namespace tws_shell {

const char Encoder::kZero = '\0';

// bool编码
template<>
void Encoder::Encode<bool>(std::ostream& os, bool value) {
  Encoder::Encode<int>(os, value ? 1 : 0);
}

// double编码
template<>
void Encoder::Encode<double>(std::ostream& os, double value) {
  os << std::setprecision(8) << value << kZero;
}

} // namespace tws_shell
