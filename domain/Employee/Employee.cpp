#include "Employee.h"

namespace booksa {
  Employee::Employee(const Name &name,
                     const Address &address):
    name_(name),
    address_(address)
  {

  }

  Employee::Employee(unsigned long int id, const Name &name,
                     const Address &address):
    name_(name),
    address_(address),
    IEntity(id)
  {

  }

  void Employee::addServiceCompetence(Competence service_name) {
    competences_.insert(service_name);
  }

  void Employee::removeServiceCompetence(Competence service_name) {
    competences_.erase(service_name);
  }

  Name Employee::getName() const {
    return name_;
  }

  void Employee::setName(Name new_name) {
    name_ = new_name;
  }

} // namespace booksa
