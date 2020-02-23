#include "Service.h"

namespace booksa {

  Service::Service(const NeededEmployees &needed_employees) :
    needed_employees_(needed_employees)
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
