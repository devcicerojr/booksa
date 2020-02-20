#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../Common/IEntity.h"
#include "../Common/Name.h"
#include "../Common/Address.h"
#include "../Asset/Service.h"
#include <unordered_set>

namespace booksa {

  class Employee : IEntity
  {
  private:
    Name name_;
    Address address_;
    std::unordered_set<Competence> competences_;
  public:
    Employee() = delete;
    explicit Employee(const Name &name, const Address &address);
    explicit Employee(unsigned long int id, const Name &name, const Address &address);
    virtual ~Employee();

    void addServiceCompetence(Competence service_name);
    void removeServiceCompetence(Competence service_name);
    Name getName() const;
    void setName(Name new_name);
  };

} // namespace booksa

#endif // EMPLOYEE_H
