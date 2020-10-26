#pragma once

#include "../Common/IEntity.h"
#include "../BusinessCalendar/BusinessCalendar.h"
#include "../Asset/Asset.h"
#include "../Customer/Customer.h"
#include "../Employee/Employee.h"

#include <vector>
#include <memory>
#include <map>
namespace booksa {

  using std::string;
  using std::vector;
  using std::shared_ptr;
  using std::unique_ptr;
  using std::map;

  class Business : IEntity
  {
  private:
    // Try to keep those vectors sorted to improve lookup
    string name_;
    vector<unique_ptr<Asset>> assets_;
    vector<shared_ptr<Customer>> customers_;
    unique_ptr<BusinessCalendar> calendar_;
    vector<unique_ptr<Employee>> employees_;
  public:
    Business() = delete;
    explicit Business(unique_ptr<BusinessCalendar> calendar);
    string getName() const;
    void setName(string str);
    void addAsset(std::unique_ptr<Asset> &&asset);
    void removeAsset(Asset const &asset);
    bool isAssetMember(Asset const &asset);
    void addCustomer(const shared_ptr<Customer> customer);
    void removeCustomer(const shared_ptr<Customer> customer);
    bool isCustomerMember(const shared_ptr<Customer> customer);
    void addEmployee(unique_ptr<Employee> &&employee);
    bool removeEmployee(Employee const &employee);
    bool isEmployeeMember(Employee const &employee);
    const BusinessCalendar& getCalendar();
  };

} // namespaces booksa

