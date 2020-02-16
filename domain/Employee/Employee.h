#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "../Common/Entity.h"
#include "../Common/Name.h"

namespace booksa {

  class Employee : Entity
  {
  private:
    Name name_;
  public:
    Employee() = delete;
    Employee(unsigned int id);
    virtual ~Employee();
  };

} // namespace booksa

#endif // EMPLOYEE_H
