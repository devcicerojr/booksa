#ifndef PRICE_H
#define PRICE_H

#include <string>

namespace booksa {

  struct Currency {
    std::string name;
    std::string symbol;

    // use Dollar as Default
    Currency(std::string name = "US Dollar",
             std::string symbol = "$"){}
  };

  struct Price {
    unsigned int value = 0;
    unsigned short int cents = 0;
    Currency currency;
  };
} // namespace booksa

#endif // PRICE_H
