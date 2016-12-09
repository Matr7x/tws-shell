#ifndef TWS_SHELL_ENCODER_H_
#define TWS_SHELL_ENCODER_H_

#include <iostream>

using std::cout;
using std::endl;

namespace tws_shell {

template<class T>
class Decoder {

public:
  static int Decode(char* ptr, int sieze, T& value);

private:
  static const char* FindZero(char*& ptr, int size);

};

template<>
int Decoder<int>::Decode(char* ptr, int size, int& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    return -1;
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = atoi(ptr);
  return decoded;
}

template<class T>
const char* Decoder<T>::FindZero(char*& ptr, int size) {
  return static_cast<const char*>(memchr(ptr, 0, size));
}

} // namespace tws_shell

#endif//TWS_SHELL_ENCODER_H_
