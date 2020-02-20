#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>

namespace booksa {
  struct Address {
    std::string street;
    std::string city;
    std::string zip_code;
  };
} // namespace booksa

#endif // ADDRESS_H
