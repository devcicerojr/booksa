#pragma once

#include "../Common/IEntity.h"
#include "../Common/Price.h"
#include <string>

namespace booksa {
  using std::string;

  class Asset : IEntity
  {
  public:
    explicit Asset(string const &name, Price const &price);
    virtual ~Asset() = 0;
    virtual string getName() const;
    virtual Price getPrice() const;

    Asset(Asset &&rh_asset);
    Asset& operator = (Asset &&rh_asset);
    bool operator < (Asset const &rh_asset);
    bool operator == (Asset const &rh_asset);
    bool operator != (Asset const &rh_asset);
    bool operator > ( Asset const &rh_asset);

   protected:
    string name_;
    Price price_;
  };

} // namespace booksa
