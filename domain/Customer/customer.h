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
      explicit Customer(unsigned int id, const Name& name, const Address& address);
      ~Customer();

      void setName(const Name& name);
      Name getName();
      void setAddress(const Address& address);
      Address getAddress();
  };
} // namespace booksa
#endif // CUSTOMER_H
