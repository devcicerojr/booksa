#include "Employee.h"
#include "../Asset/Service.h"
#include "../Common/Name.h"

#include <algorithm>

namespace booksa {
  Employee::Employee(const Name &name,
                     const Address &address):
    name_(name),
    address_(address),
    role_(DEFAULT)
  {

  }

  Employee::Employee(unsigned long int id, const Name &name,
                     const Address &address):
    IEntity(id),
    name_(name),
    address_(address),
    role_(DEFAULT)
  {

  }

  Employee::~Employee()
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

  Address Employee::getAddress() const
  {
    return address_;
  }

  void Employee::setAddress(const Address &new_address)
  {
    address_ = new_address;
  }

  Phone Employee::getPhone() const
  {
    return phone_;
  }

  void Employee::setPhone(const Phone &new_phone)
  {
    phone_ = new_phone;
  }

  EmployeeRole Employee::getRole() const
  {
    return role_;
  }

  void Employee::setRole(EmployeeRole new_role)
  {
    role_ = new_role;
  }

  set<shared_ptr<Service> > Employee::getServices() const
  {
    return competences_;
  }

  void Employee::setServices(set<shared_ptr<Service> > &&new_competences)
  {
    competences_ = std::move(new_competences);
  }

  Employee::Employee(const Employee &&rh_employee) :
    name_(rh_employee.getName()),
    address_(rh_employee.getAddress()),
    phone_(rh_employee.getPhone()),
    competences_(std::move(rh_employee.competences_))
  {

  }

  Employee &Employee::operator =(Employee const &&rh_employee)
  {
    if (*this != rh_employee) {
      name_ = rh_employee.name_;
      address_ = rh_employee.getAddress();
      phone_ = rh_employee.getPhone();
      competences_ = std::move(rh_employee.competences_);
    }
    return *this;
  }

  bool Employee::operator ==(Employee const &rh_employee) const
  {
    if (name_ == rh_employee.getName() &&
        phone_ == rh_employee.getPhone() &&
        address_ == rh_employee.getAddress())
      return true;
    return false;
  }


  bool Employee::operator !=(Employee const &rh_employee) const {
    return !((*this)==rh_employee);
  }

  bool Employee::operator >(const Employee &rh_employee) const {
    if (name_.last_name > rh_employee.getName().last_name)
      return true;
    if (name_.last_name == rh_employee.getName().last_name) {
      return (name_.first_name > rh_employee.getName().first_name)? true : false;
    }
    return false;
  }

} // namespace booksa
