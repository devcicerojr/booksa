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

  bool operator == (Address const &lh_address , Address const &rh_address) {
    if (lh_address.street == rh_address.street &&
          lh_address.city == rh_address.city &&
          lh_address.street_number == rh_address.street_number &&
          lh_address.apartment_number == rh_address.apartment_number) {
      return true;
    }
    return false;
  }
} // namespace booksa

