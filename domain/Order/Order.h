#pragma once

#include "../Common/IEntity.h"
#include "../Common/Price.h"

namespace booksa {

  class Order : IEntity
  {
  public:
    Order();
    virtual ~Order() = 0;
  };

} // namespace booksa
