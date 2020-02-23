#ifndef SERVICE_H
#define SERVICE_H

#include "Asset.h"
#include <string>

namespace booksa {
  class Service : Asset
  {

  public:
    Service();
    std::string getName() override;
    Price getPrice() override;
  };

} //namespace booksa
#endif // SERVICE_H
