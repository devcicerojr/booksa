#ifndef BUSINESS_H
#define BUSINESS_H

#include "../Common/IEntity.h"
#include "../Common/Role.h"
#include "../BusinessCalendar/BusinessCalendar.h"
#include "../Asset/Asset.h"
#include "../Customer/Customer.h"
#include "../Employee/Employee.h"



#include <vector>
#include <memory>
#include <map>
namespace booksa {

  class Business : IEntity
  {
  private:
    std::vector<std::shared_ptr<Asset>> assets_;
    std::vector<std::shared_ptr<Customer>> customers_;
    BusinessCalendar calendar_;
    std::map<std::shared_ptr<Employee>, EmployeeRole> employees_;
  public:
    Business() = delete;
    explicit Business(const BusinessCalendar &calendar);
    void addAsset(const Asset &asset);
    void removeAsset(const Asset &asset);
    void addCustomer(const Customer &customer);
    void removeCustomer(const Customer &customer);
    void addEmployee(const Employee &employee, EmployeeRole role = DEFAULT);
    void removeEmployee(const Employee &employee);
    BusinessCalendar& getCalendar() const;
  };

} // namespaces booksa

#endif // BUSINESS_H
