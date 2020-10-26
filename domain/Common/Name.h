#pragma once

#include <string>

namespace booksa {

  struct Name {
    std::string first_name = "";
    std::string last_name = "";
  };

  bool operator == (Name const &lh_name, Name const &rh_name) {
      return (lh_name.first_name == rh_name.first_name && lh_name.last_name == rh_name.last_name)? true : false;
  }

} // namespace booksa
