#include "Asset.h"

namespace booksa {
  Asset::Asset(const std::string &name, const Price &price) :
    name_(name),
    price_(price),
    IEntity(0)
  {

  }

} // namespace booksa
