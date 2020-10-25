#pragma once

#include "../Common/IEntity.h"
#include "../Common/Price.h"

namespace booksa {

  class Asset : IEntity
  {
  public:
    explicit Asset(std::string const &name, Price const &price);
    virtual ~Asset() = 0;
    virtual std::string getName() const = 0;
    virtual Price getPrice() const = 0;

    bool operator < (Asset const &rh_asset);

   protected:
    std::string name_;
    Price price_;
  };

} // namespace booksa
