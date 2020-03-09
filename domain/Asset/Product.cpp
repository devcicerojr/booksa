#include "Product.h"

namespace booksa {

  Product::Product(const std::string &name, const Price &price)
    : Asset(name, price)
  {
  }

  std::string Product::getName() const {
    return name_;
  }

  Price Product::getPrice() const {
    return price_;
  }


} // namespace booksa
