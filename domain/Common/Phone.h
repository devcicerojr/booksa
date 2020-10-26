#pragma once
#include <string>

namespace booksa {

  struct Phone {
    std::string number = "";
  };

  bool operator == (Phone const &lh_phone, Phone const &rh_phone) {
    return (lh_phone.number == rh_phone.number)? true : false;
  }
} // namespace booksa
