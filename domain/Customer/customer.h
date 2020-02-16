#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../Common/Entity.h"
#include "../Common/Address.h"
#include "../Common/Name.h"
#include <string>


namespace booksa {

  class Customer : Entity
  {
  private:
    Name name_;
    Address address_;

    public:
      Customer() = delete;
      explicit Customer(Name name, Address address);
      ~Customer();
  };
} // namespace booksa
#endif // CUSTOMER_H
