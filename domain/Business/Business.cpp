#include "Business.h"
#include "../Common/CustomContainers.h"
#include <algorithm>

namespace booksa {

  Business::Business(const BusinessCalendar &calendar):
  IEntity(0)
  {
    calendar_ = calendar;
  }

  void Business::addAsset(const std::shared_ptr<Asset> asset) {
    insert_sorted<std::shared_ptr<Asset>>(assets_, asset);
    auto last_uniq_it = std::unique(assets_.begin(), assets_.end());
    assets_.erase(last_uniq_it, assets_.end());
  }

  void Business::removeAsset(const std::shared_ptr<Asset> asset) {
    auto it = std::find(assets_.begin(), assets_.end(), asset);
    if (it != assets_.end())
      assets_.erase(it);
  }

  void Business::addCustomer(const std::shared_ptr<Customer> customer) {
    insert_sorted<std::shared_ptr<Customer>>(customers_, customer);
    auto last_uniq_it = std::unique(customers_.begin(), customers_.end());
    customers_.erase(last_uniq_it, customers_.end());
  }

  void Business::removeCustomer(const std::shared_ptr<Customer> customer) {
    auto it = std::find(customers_.begin(), customers_.end(), customer);
    if (it != customers_.end())
      customers_.erase(it);
  }

  void Business::addEmployee(const std::shared_ptr<Employee> employee, EmployeeRole role) {
    employees_.insert(std::make_pair(employee, role));
  }

  void Business::removeEmployee(const std::shared_ptr<Employee> employee) {
    employees_.erase(employee);
  }



} // namespace booksa
