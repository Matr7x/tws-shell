#include "decoder.h"

namespace tws_shell {

int Decoder::Decode(char* ptr, int size, int& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    exit(255);
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = atoi(ptr);
  return decoded;
}

int Decoder::Decode(char* ptr, int size, long& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    exit(255);
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = atoi(ptr);
  return decoded;
}

int Decoder::Decode(char* ptr, int size, bool& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    exit(255);
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = atoi(ptr);
  return decoded;
}

int Decoder::Decode(char* ptr, int size, string& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    exit(255);
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = ptr;
  return decoded;
}

int Decoder::Decode(char* ptr, int size, double& value) {
  // 寻找zero
  const char* zero_ptr = FindZero(ptr, size);

  // 找不到zero的情况
  if (NULL == zero_ptr) {
    cout << "Field end not found!" << endl;
    exit(255);
  }

  // 解码int
  int decoded = zero_ptr - ptr + 1;
  value = atof(ptr);
  return decoded;
}

const char* Decoder::FindZero(char*& ptr, int size) {
  return static_cast<const char*>(memchr(ptr, 0, size));
}

} // namespace tws_shell
