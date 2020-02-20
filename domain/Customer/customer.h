#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../Common/IEntity.h"
#include "../Common/Address.h"
#include "../Common/Name.h"
#include <string>


namespace booksa {

  class Customer : IEntity
  {
  private:
    Name name_;
    Address address_;

    public:
      Customer() = delete;
      explicit Customer(const Name &name, const Address &address);
      explicit Customer(unsigned long int id, const Name& name, const Address& address);
      ~Customer();

      void setName(const Name& name);
      Name getName() const;
      void setAddress(const Address& address);
      Address getAddress() const;
  };
} // namespace booksa
#endif // CUSTOMER_H
