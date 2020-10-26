#pragma once

#include "../Common/IEntity.h"

#include <string>
#include <vector>
#include <memory>
#include <map>

namespace booksa {

  using std::string;
  using std::vector;
  using std::shared_ptr;
  using std::unique_ptr;
  using std::map;

  class Employee;
  class Customer;
  class Asset;
  class BusinessCalendar;

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
    bool isAssetMember(Asset const &asset) const;
    void addCustomer(const shared_ptr<Customer> customer);
    void removeCustomer(const shared_ptr<Customer> customer);
    bool isCustomerMember(const shared_ptr<Customer> customer) const;
    void addEmployee(unique_ptr<Employee> &&employee);
    bool removeEmployee(Employee const &employee);
    bool isEmployeeMember(Employee const &employee) const;
    const BusinessCalendar& getCalendar() const;
  };

} // namespaces booksa

