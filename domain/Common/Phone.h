#pragma once
#include <string>

namespace booksa {

  struct Phone {
    std::string number = "";

    bool operator == (Phone const &rh_phone) const {
      return (number == rh_phone.number)? true : false;
    }
  };

} // namespace booksa
