#pragma once

#include <string>

namespace booksa {

  struct Name {
    std::string first_name = "";
    std::string last_name = "";

    bool operator == (Name const &rh_name) const {
        return (first_name == rh_name.first_name && last_name == rh_name.last_name)? true : false;
    }
  };


} // namespace booksa
