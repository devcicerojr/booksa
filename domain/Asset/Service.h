#pragma once

#include "Asset.h"
#include "../Common/Time.h"
#include <string>

namespace booksa {

  // how many employees min/max needed to perform this service
  struct NeededEmployees {
    unsigned short int minimum = 1;
    unsigned short int maximum = 1;
    NeededEmployees(unsigned short int min = 1,
                          unsigned short int max = 1) {
      if (min < 1) minimum = 1;
      if (max < min) maximum = min;
    }
  };

  class Service : Asset
  {

  private:
    NeededEmployees needed_employees_{};
    unsigned int duration_min = 10;
  public:
    Service() = delete;
    Service(const std::string &name, const Price &price, const NeededEmployees &needed_employees = NeededEmployees(1,1));
    std::string getName() const override;
    Price getPrice() const override;
    unsigned short int getMinEmployeesNeeded() const;
  };

} //namespace booksa
