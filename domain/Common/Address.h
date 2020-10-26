#pragma once
#include <string>

namespace booksa {

  struct Address {
    std::string street = "";
    std::string city = "";
    std::string street_number = "";
    std::string apartment_number = "";
    std::string zip_code = "";

    bool operator == (Address const &rh_address) const {
      if (street == rh_address.street &&
            city == rh_address.city &&
            street_number == rh_address.street_number &&
            apartment_number == rh_address.apartment_number) {
        return true;
      }
      return false;
    }
  };
} // namespace booksa

