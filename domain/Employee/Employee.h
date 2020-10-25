#pragma once

#include "../Common/IEntity.h"
#include "../Common/Name.h"
#include "../Common/Address.h"
#include "../Common/Phone.h"

#include <set>
#include <memory>

namespace booksa {

  class Service;
  class Employee : IEntity
  {
  private:
    Name name_;
    Address address_;
    Phone phone_;
    std::set<std::shared_ptr<Service>> competences_{};
  public:
    Employee() = delete;
    explicit Employee(Name const &name, Address const &address);
    explicit Employee(unsigned long int id, Name const &name, Address const &address);
    virtual ~Employee();

    void addServiceCompetence(std::shared_ptr<Service> const &service);
    bool removeServiceCompetence(Service const &service);
    Name getName() const;
    void setName(Name const &new_name);
  };

} // namespace booksa

