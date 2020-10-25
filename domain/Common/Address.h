#pragma once
#include <string>

namespace booksa {

  struct Address {
    std::string street = "";
    std::string city = "";
    std::string street_number = "";
    std::string apartment_number = "";
    std::string zip_code = "";
  };
} // namespace booksa

