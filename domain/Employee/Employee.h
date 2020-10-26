#pragma once

#include "../Common/IEntity.h"
#include "../Common/Address.h"
#include "../Common/Phone.h"
#include "../Common/Name.h"
#include "../Asset/Service.h"

#include <set>
#include <memory>

namespace booksa {

  using std::set;
  using std::shared_ptr;

  enum EmployeeRole {
    DEFAULT,
    MANAGER,
    ADMIN
  };


  class Employee : IEntity
  {
  private:
    Name name_;
    Address address_;
    Phone phone_;
    EmployeeRole role_;
    set<shared_ptr<Service>> competences_{};
  public:
    Employee() = delete;
    explicit Employee(Name const &name, Address const &address);
    explicit Employee(unsigned long int id, Name const &name, Address const &address);
    Employee(Employee &employee) = default;
    Employee& operator = (Employee &employee) = default;

    virtual ~Employee();

    void addServiceCompetence(shared_ptr<Service> const &service);
    bool removeServiceCompetence(Service const &service);

    Name getName() const;
    void setName(Name const &new_name);
    Address getAddress() const;
    void setAddress(Address const &new_address);
    Phone getPhone() const;
    void setPhone(Phone const &new_phone);
    EmployeeRole getRole() const;
    void setRole(EmployeeRole new_role);


    set<shared_ptr<Service>> getServices() const;
    void setServices(set<shared_ptr<Service>> &&new_competences);


    Employee(Employee const &&rh_employee);
    Employee& operator = (Employee const &&rh_employee);
    bool operator == (Employee const &rh_employee) const;
    bool operator != (Employee const &rh_employee) const;
    bool operator > (Employee const &rh_employee) const;
  };

} // namespace booksa

