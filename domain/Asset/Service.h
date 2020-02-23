#ifndef SERVICE_H
#define SERVICE_H

#include "Asset.h"
#include "../Common/Time.h"
#include <string>

namespace booksa {

  // how many employees min/max needed to perform this service
  struct NeededEmployees {
    unsigned short int minimum = 1;
    unsigned short int maximum = 1;
    NeededEmployees(unsigned short int min,
                          unsigned short int max) {
      if (min < 1) minimum = 1;
      if (max < min) maximum = min;
    }
  };

  class Service : Asset
  {

  private:
    NeededEmployees needed_employees_{1,1};
    unsigned int duration_min = 10;
  public:
    Service(const NeededEmployees &needed_employees);
    std::string getName() const override;
    Price getPrice() const override;
    unsigned short int getMinEmployeesNeeded() const;
  };

} //namespace booksa
#endif // SERVICE_H
