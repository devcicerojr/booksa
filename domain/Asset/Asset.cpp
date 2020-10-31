#include "Asset.h"

namespace booksa {

  Asset::Asset(std::string const &name, Price const &price) :
    name_(name),
    price_(price){}

  std::string Asset::getName() const
  {
    return name_;
  }

  Price Asset::getPrice() const
  {
    return price_;
  }

  Asset::Asset(Asset &&rh_asset)
  {
    name_ = rh_asset.getName();
    price_ = std::move(rh_asset.getPrice());
  }

  Asset &Asset::operator =(Asset &&rh_asset)
  {
    if (this != &rh_asset) {
      name_ = rh_asset.getName();
      price_ = std::move(rh_asset.getPrice());
    }
    return *this;
  };

  bool Asset::operator < (const Asset &rh_asset)
  {
    return (name_ < rh_asset.getName()) ? true : false;
  }

  bool Asset::operator ==(const Asset &rh_asset)
  {
    return (name_ == rh_asset.getName() && price_ == rh_asset.getPrice())? true : false;
  }

  bool Asset::operator !=(const Asset &rh_asset)
  {
    return !(*this == rh_asset);
  }

  bool Asset::operator >(const Asset &rh_asset)
  {
    return (name_ > rh_asset.getName()) ? true : false;
  }

} // namespace booksa
