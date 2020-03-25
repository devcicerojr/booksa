#include "WorkDay.h"
#include "../Common/CustomContainers.h"

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

  DateRepr WorkDay::getDate() const
  {
    return date_;
  }

  void WorkDay::addService(std::shared_ptr<Service> service)
  {
    // keeping sorted and removing duplicates
    insert_sorted<std::shared_ptr<Service>>(services_, service);
    auto last_uniq_it = std::unique(services_.begin(), services_.end());
    services_.erase(last_uniq_it, services_.end());
  }

  void WorkDay::removeService(std::shared_ptr<Service> service) {
    auto it = std::lower_bound(services_.begin(), services_.end(), service);
    if (it != services_.end())
      services_.erase(it);
  }

  void WorkDay::setHoliday(bool val)
  {
    is_holiday_ = val;
  }

  bool WorkDay::isHoliday() const
  {
    return is_holiday_;
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
