#include "Business.h"
#include "../Common/CustomContainers.h"
#include "../Asset/Asset.h"
#include "../Employee/Employee.h"
#include "../BusinessCalendar/BusinessCalendar.h"

#include <algorithm>

namespace booksa {

  Business::Business(std::string name) :
    name_(name)
  {

  }

  Business::Business(std::unique_ptr<BusinessCalendar> calendar):
  IEntity(0) {
    calendar_ = std::move(calendar);
  }

  std::string Business::getName() const {
    return name_;
  }

  void Business::setName(std::string str) {
    name_ = str;
  }

  void Business::addAsset(std::unique_ptr<Asset> &&asset) {
    // keeping sorted and removing duplicates
    unq_insert_sorted<std::unique_ptr<Asset>>(assets_, std::move(asset));
    auto last_uniq_it = std::unique(assets_.begin(), assets_.end());
    assets_.erase(last_uniq_it, assets_.end());
  }

  void Business::removeAsset(Asset const &asset) {
    auto it = std::lower_bound(begin(assets_), end(assets_), asset,
              [](std::unique_ptr<Asset> &elem, Asset const &asset) {
                return (*elem < asset)? true : false;
              });
    if (it != assets_.end())
      assets_.erase(it);
  }

  bool Business::isAssetMember(Asset const &asset) const {
    auto found =  std::find_if(assets_.begin(), assets_.end(),
          [&asset](std::unique_ptr<Asset> const &elem) {
      return ((*elem) < asset) ? true : false;
    });

    return (found != end(assets_))? true : false;
  }

  void Business::addCustomer(const std::shared_ptr<Customer> customer) {
    // keeping sorted and removing duplicates
    insert_sorted<std::shared_ptr<Customer>>(customers_, customer);
    auto last_uniq_it = std::unique(customers_.begin(), customers_.end());
    customers_.erase(last_uniq_it, customers_.end());
  }

  void Business::removeCustomer(const std::shared_ptr<Customer> customer) {
    auto it = std::lower_bound(customers_.begin(), customers_.end(), customer);
    if (it != customers_.end())
      customers_.erase(it);
  }

  bool Business::isCustomerMember(const std::shared_ptr<Customer> customer) const {
    return std::binary_search(customers_.begin(), customers_.end(), customer);
  }

  void Business::addEmployee(std::unique_ptr<Employee> &&employee) {
    unq_insert_sorted<std::unique_ptr<Employee>>(employees_, std::move(employee));
  }

  bool Business::removeEmployee(Employee const &employee) {
    auto found = find_if(begin(employees_), end(employees_),
                 [&employee](std::unique_ptr<Employee> const &elem) {
                   return ((*elem).getName() == employee.getName()) ? true : false;
    });

    if (found != end(employees_)) {
      employees_.erase(found);
      return true;
    }
    return false;

  }

  bool Business::isEmployeeMember(Employee const &employee) const {
    auto found = find_if(begin(employees_), end(employees_),
                         [&](std::unique_ptr<Employee> const &elem) {
                           return ((*elem) == employee) ? true : false;
            });
    return (found != end(employees_)) ? true : false;
  }

  const BusinessCalendar& Business::getCalendar() const {
    return *calendar_;
  }



} // namespace booksa
