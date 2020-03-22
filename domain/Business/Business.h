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
    // Try to keep those vectors sorted to improve lookup
    std::string name_;
    std::vector<std::shared_ptr<Asset>> assets_;
    std::vector<std::shared_ptr<Customer>> customers_;
    std::unique_ptr<BusinessCalendar> calendar_;
    std::map<std::shared_ptr<Employee>, EmployeeRole> employees_;
  public:
    Business() = delete;
    explicit Business(std::unique_ptr<BusinessCalendar> calendar);
    std::string getName() const;
    void setName(std::string str);
    void addAsset(const std::shared_ptr<Asset> asset);
    void removeAsset(const std::shared_ptr<Asset> asset);
    bool isAssetMember(const std::shared_ptr<Asset> asset);
    void addCustomer(const std::shared_ptr<Customer> customer);
    void removeCustomer(const std::shared_ptr<Customer> customer);
    bool isCustomerMember(const std::shared_ptr<Customer> customer);
    void addEmployee(const std::shared_ptr<Employee> employee, EmployeeRole role = DEFAULT);
    void removeEmployee(const std::shared_ptr<Employee> employee);
    bool isEmployeeMember(const std::shared_ptr<Employee> employee);
    const BusinessCalendar& getCalendar();
  };

} // namespaces booksa

#endif // BUSINESS_H
