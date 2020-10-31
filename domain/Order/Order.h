#pragma once

#include "../Common/IEntity.h"
#include "../Common/Price.h"

namespace booksa {

  enum OrderStatus {
    BOOKED,
    CANCELED,
    FINISHED
  };

  class Order : IEntity
  {
  public:
    Order();
    virtual ~Order() = 0;
  };

} // namespace booksa
