#include "Customer.h"

namespace booksa {
  Customer::Customer(unsigned int id, const Name& name, const Address& address) :
    name_(name),
    address_(address),
    Entity(id) {

  }

  void booksa::Customer::setName(const Name &name) {
    name_ = name;
  }

  Name booksa::Customer::getName() {
    return name_;
  }

  void booksa::Customer::setAddress(const Address &address) {
    address_ = address;
  }

  Address Customer::getAddress() {
    return address_;
  }
} //namespace booksa
