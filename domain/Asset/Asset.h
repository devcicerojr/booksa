#ifndef ASSET_H
#define ASSET_H

#include "../Common/IEntity.h"
#include "../Common/Price.h"

namespace booksa {

  class Asset : IEntity
  {
  public:
    virtual ~Asset();
    virtual std::string getName() const = 0;
    virtual Price getPrice() const = 0;
  protected:
    std::string name_;
    Price price_;
    Asset();
  };

} // namespace booksa

#endif // ASSET_H
