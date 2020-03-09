#include "Service.h"

namespace booksa {

  Service::Service(const std::string &name, const Price &price, const NeededEmployees &needed_employees) :
    needed_employees_(needed_employees),
    Asset(name, price)
  {

  }

  std::string Service::getName() const
  {
    return name_;
  }

  Price Service::getPrice() const
  {
    return price_;
  }

  unsigned short int Service::getMinEmployeesNeeded() const {
    return needed_employees_.minimum;
  }
} // namespace booksa
