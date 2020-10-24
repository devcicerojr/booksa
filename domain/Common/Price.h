#ifndef PRICE_H
#define PRICE_H

#include <string>
#include <vector>

namespace booksa {

  struct Currency {
    std::string name;
    std::string symbol;

    // use Dollar as Default
    Currency(std::string name = "US Dollar",
             std::string symbol = "$") : name(name), symbol(symbol) {}
  };

  // This enum  determines the size of vector RegCurrencies
  enum Currencies {
    US_DOLLAR,
    BR_REAL,
    EU_EURO,
    PL_ZLOTY,
    Count
  };

  const std::vector<Currency> RegCurrencies = {Currency("US Dollar", "$"),
                                               Currency("BR Real", "R$"),
                                               Currency("EU Euro", "€"),
                                               Currency("PL Zloty","Zł")};

  struct Price {
    unsigned int value = 0;
    unsigned short int cents = 0;
    Currency currency;

    Price(unsigned int val, unsigned int cen,
          const Currency &curr) :
      value(val),
      cents(cen),
      currency(curr){}
    Price(const Price &r_price) :
      value(r_price.value),
      cents(r_price.cents),
      currency(r_price.currency){}


  };
} // namespace booksa

#endif // PRICE_H
