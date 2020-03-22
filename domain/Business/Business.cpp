#include "Business.h"
#include "../Common/CustomContainers.h"
#include <algorithm>

namespace booksa {

  Business::Business(std::unique_ptr<BusinessCalendar> calendar):
  IEntity(0)
  {
    calendar_ = std::move(calendar);
  }

  std::string Business::getName() const
  {
    return name_;
  }

  void Business::setName(std::string str)
  {
    name_ = str;
  }

  void Business::addAsset(const std::shared_ptr<Asset> asset) {
    insert_sorted<std::shared_ptr<Asset>>(assets_, asset);
    auto last_uniq_it = std::unique(assets_.begin(), assets_.end());
    assets_.erase(last_uniq_it, assets_.end());
  }

  void Business::removeAsset(const std::shared_ptr<Asset> asset) {
    auto it = std::lower_bound(assets_.begin(), assets_.end(), asset);
    if (it != assets_.end())
      assets_.erase(it);
  }

  bool Business::isAssetMember(const std::shared_ptr<Asset> asset)
  {
    return std::binary_search(assets_.begin(), assets_.end(), asset);
  }

  void Business::addCustomer(const std::shared_ptr<Customer> customer) {
    insert_sorted<std::shared_ptr<Customer>>(customers_, customer);
    auto last_uniq_it = std::unique(customers_.begin(), customers_.end());
    customers_.erase(last_uniq_it, customers_.end());
  }

  void Business::removeCustomer(const std::shared_ptr<Customer> customer) {
    auto it = std::lower_bound(customers_.begin(), customers_.end(), customer);
    if (it != customers_.end())
      customers_.erase(it);
  }

  bool Business::isCustomerMember(const std::shared_ptr<Customer> customer)
  {
    return std::binary_search(customers_.begin(), customers_.end(), customer);
  }

  void Business::addEmployee(const std::shared_ptr<Employee> employee, EmployeeRole role) {
    employees_.insert(std::make_pair(employee, role));
  }

  void Business::removeEmployee(const std::shared_ptr<Employee> employee) {
    employees_.erase(employee);
  }

  bool Business::isEmployeeMember(const std::shared_ptr<Employee> employee)
  {
    auto it = employees_.find(employee);
    return it != employees_.end() ? true : false;
  }

  const BusinessCalendar& Business::getCalendar() {
    return *calendar_;
  }



} // namespace booksa
