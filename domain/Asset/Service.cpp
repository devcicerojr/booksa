#include "Service.h"

namespace booksa {

  Service::Service(const std::string &name, const Price &price, const NeededEmployees &needed_employees) :
    Asset(name,price),
    needed_employees_(needed_employees)
  {

  }

  std::string Service::getName() const
  {
    return name_;
  }

  Price Service::getPrice() const
  {
    return this->price_;
  }

  unsigned short int Service::getMinEmployeesNeeded() const {
    return needed_employees_.minimum;
  }

  void Service::setDurationInMinutes(unsigned int new_duration)
  {
    minute_duration_ = new_duration;
  }

  unsigned int Service::getDurationInMinutes() const
  {
    return minute_duration_;
  }
} // namespace booksa
