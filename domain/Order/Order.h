#ifndef ORDER_H
#define ORDER_H

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

#endif // ORDER_H
