#include "Employee.h"
#include "../Asset/Service.h"

#include <algorithm>

namespace booksa {
  Employee::Employee(const Name &name,
                     const Address &address):
    name_(name),
    address_(address)
  {

  }

  Employee::Employee(unsigned long int id, const Name &name,
                     const Address &address):
    IEntity(id),
    name_(name),
    address_(address)
  {

  }

  void Employee::addServiceCompetence(const std::shared_ptr<Service> &service) {
    competences_.insert(service);
  }

  bool Employee::removeServiceCompetence(Service const &service) {
    auto found = std::find_if(begin(competences_), end(competences_),
                              [&service](std::shared_ptr<Service> element) {
                   return (service.getName() == (*element).getName());
                 });
    if (found != end(competences_)) {
      competences_.erase(found);
      return true;
    }
    return false;
  }

  Name Employee::getName() const {
    return name_;
  }

  void Employee::setName(Name const &new_name) {
    name_ = new_name;
  }

} // namespace booksa
