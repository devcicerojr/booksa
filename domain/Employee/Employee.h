#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../Common/IEntity.h"
#include "../Common/Name.h"
#include "../Common/Address.h"
#include "../Asset/Service.h"
#include <unordered_set>
#include <memory>

namespace booksa {

  class Employee : IEntity
  {
  private:
    Name name_;
    Address address_;
    std::unordered_set<std::shared_ptr<Service>> competences_;
  public:
    Employee() = delete;
    explicit Employee(const Name &name, const Address &address);
    explicit Employee(unsigned long int id, const Name &name, const Address &address);
    virtual ~Employee();

    void addServiceCompetence(const std::shared_ptr<Service> &service);
    void removeServiceCompetence(const std::shared_ptr<Service> &service);
    Name getName() const;
    void setName(Name new_name);
  };

} // namespace booksa

#endif // EMPLOYEE_H
