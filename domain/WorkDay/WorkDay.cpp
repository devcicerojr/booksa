#include "WorkDay.h"

namespace booksa {

  WorkDay::WorkDay(const DateRepr &date) :
    IEntity(0)
  {

  }

  Month WorkDay::getMonth() const {
    return date_.month;
  }

  Day WorkDay::getDay() const {
    return date_.day;
  }

  Year WorkDay::getYear() const {
    return date_.year;
  }
}// namespace booksa
