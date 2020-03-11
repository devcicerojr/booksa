#include "WorkDay.h"

namespace booksa {

  WorkDay::WorkDay(const DateRepr &date) :
    IEntity(0)
  {

  }

  Day WorkDay::getDay() const {
    return date_.day;
  }

  Month WorkDay::getMonth() const {
    return date_.month;
  }

  Year WorkDay::getYear() const {
    return date_.year;
  }

  bool WorkDay::operator <(const WorkDay &r_wd) const {
    Year year = getYear(), r_year = r_wd.getYear();
    Month month = getMonth(), r_month = r_wd.getMonth();
    Day day = getDay(), r_day = r_wd.getDay();

    if (year < r_year)
      return true;
    if (year == r_year && month < r_month)
      return true;
    if (year == r_year && month == r_month && day < r_day)
      return true;
    return false;
  }

  bool WorkDay::operator >(const WorkDay &r_wd) const {
    Year year = getYear(), r_year = r_wd.getYear();
    Month month = getMonth(), r_month = r_wd.getMonth();
    Day day = getDay(), r_day = r_wd.getDay();

    if (year > r_year)
      return true;
    if (year == r_year && month > r_month)
      return true;
    if (year == r_year && month == r_month && day > r_day)
      return true;
    return false;
  }

  bool WorkDay::operator ==(const WorkDay &r_wd) const {
    Year year = getYear(), r_year = r_wd.getYear();
    Month month = getMonth(), r_month = r_wd.getMonth();
    Day day = getDay(), r_day = r_wd.getDay();

    if (year == r_year && month == r_month && day == r_day)
      return true;
    return false;
  }

  bool WorkDay::operator <=(const WorkDay &r_wd) const {
    return !(*this > r_wd);
  }

  bool WorkDay::operator >=(const WorkDay &r_wd) const {
    return !(*this < r_wd);
  }

  bool WorkDay::operator !=(const WorkDay &r_wd) const {
    return !(*this == r_wd);
  }
}// namespace booksa
