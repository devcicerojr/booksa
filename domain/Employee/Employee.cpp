#include "Employee.h"

namespace booksa {
  Employee::Employee(const Name &name,
                     const Address &address):
    name_(name),
    address_(address),
    IEntity(0)
  {

  }

  Employee::Employee(unsigned long int id, const Name &name,
                     const Address &address):
    name_(name),
    address_(address),
    IEntity(id)
  {

  }

  void Employee::addServiceCompetence(const std::shared_ptr<Service> &service) {
    competences_.insert(service);
  }

  void Employee::removeServiceCompetence(const std::shared_ptr<Service> &service) {
    competences_.erase(service);
  }

  Name Employee::getName() const {
    return name_;
  }

  void Employee::setName(Name new_name) {
    name_ = new_name;
  }

} // namespace booksa
