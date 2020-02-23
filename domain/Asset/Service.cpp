#include "Service.h"

namespace booksa {
  Service::Service()
  {

  }

  std::string Service::getName()
  {
    return name_;
  }

  Price Service::getPrice()
  {
    return price_;
  }
} // namespace booksa
