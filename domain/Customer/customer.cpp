#include "Customer.h"

namespace booksa {

  Customer::Customer(const Name &name, const Address &address) :
    name_(name),
    address_(address) {

  }

  Customer::Customer(unsigned long int id, const Name& name, const Address& address) :
    IEntity(id),
    name_(name),
    address_(address) {

  }

  void booksa::Customer::setName(const Name &name) {
    name_ = name;
  }

  Name booksa::Customer::getName() const {
    return name_;
  }

  void booksa::Customer::setAddress(const Address &address) {
    address_ = address;
  }

  Address Customer::getAddress() const {
    return address_;
  }

  void Customer::setPhone(const Phone &phone)
  {
    phone_ = phone;
  }

  Phone Customer::getPhone() const
  {
    return phone_;
  }
} //namespace booksa
