#pragma once

#include <string>
#include <vector>

namespace booksa {

  struct Currency {
    std::string name;
    std::string symbol;

    // use Dollar as Default
    Currency(std::string name = "US Dollar",
             std::string symbol = "$") : name(name), symbol(symbol) {}

    bool operator == (Currency const &rh_currency);
    bool operator != (Currency const &rh_currency);
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

    Price(unsigned int val = 0, unsigned int cen = 0,
          const Currency &curr = Currency()) :
      value(val),
      cents(cen),
      currency(curr){}

    Price(const Price &r_price) :
      value(r_price.value),
      cents(r_price.cents),
      currency(r_price.currency){}

    bool operator == (Price const &rh_price);
    bool operator != (Price const &rh_price);
  };

  bool Price::operator ==(const Price &rh_price)
  {
      if (value == rh_price.value &&
              cents == rh_price.cents &&
              currency == rh_price.currency) {
          return true;
      }
      return false;
  }

  bool Price::operator !=(const Price &rh_price)
  {
      return !(*this == rh_price);
  }

  bool Currency::operator ==(const Currency &rh_currency)
  {
      return (name == rh_currency.name && symbol == rh_currency.symbol)? true : false;
  }

  bool Currency::operator !=(const Currency &rh_currency)
  {
      return !(*this == rh_currency);
  }

} // namespace booksa
