#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "../Common/IEntity.h"
#include "../Common/Address.h"
#include "../Common/Name.h"
#include "../Common/Phone.h"
#include <string>



namespace booksa {

  class Customer : IEntity
  {
  private:
    Name name_;
    Address address_;
    Phone phone_;

    public:
      Customer() = delete;
      explicit Customer(Name const &name, Address const &address);
      explicit Customer(unsigned long int id, Name const &name, Address const &address);
      ~Customer();

      void setName(Name const &name);
      Name getName() const;
      void setAddress(Address const &address);
      Address getAddress() const;
      void setPhone(Phone const &phone);
      Phone getPhone() const;
  };
} // namespace booksa
#endif // CUSTOMER_H
