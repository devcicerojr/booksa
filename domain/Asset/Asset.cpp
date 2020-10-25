#include "Asset.h"

namespace booksa {

  Asset::Asset(std::string const &name, Price const &price) :
    name_(name),
    price_(price){};

  bool Asset::operator < (const Asset &rh_asset)
  {
    return (name_ < rh_asset.getName()) ? true : false;
  }

} // namespace booksa
