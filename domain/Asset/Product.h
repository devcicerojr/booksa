#ifndef PRODUCT_H
#define PRODUCT_H

#include "Asset.h"


namespace booksa {

  class Product : Asset
  {
  public:
    Product() = delete;
    explicit Product(const std::string &name, const Price &price);
    std::string getName() const override;
    Price getPrice() const override;
    ~Product();
  };

} // namespace booksa
#endif // PRODUCT_H
