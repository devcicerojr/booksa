#include "WorkDay.h"
#include "../Common/CustomContainers.h"
#include "../Schedule/Schedule.h"

namespace booksa {

  WorkDay::WorkDay(const DateRepr &date) :
    date_(date),
    schedule_(std::make_unique<Schedule>())
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

  void WorkDay::addToSchedule(std::shared_ptr<Service> service, TimeInterval const &t_interval)
  {
    schedule_->add(std::make_pair(t_interval, service));
  }

  void WorkDay::removeFromSchedule(std::shared_ptr<Service> service, TimeInterval const &t_interval) {
    auto sch_pair = std::make_pair(t_interval, service);
    schedule_->remove(sch_pair);
  }

  void WorkDay::setHoliday(bool val)
  {
    is_holiday_ = val;
  }

  bool WorkDay::isHoliday() const
  {
    return is_holiday_;
  }

  void WorkDay::setWorkingTime(TimeInterval const &new_wt)
  {
    working_time_ = new_wt;
    schedule_->intervalCap(working_time_);
  }

  TimeInterval WorkDay::getWorkingTime() const
  {
    return working_time_;
  }

  void WorkDay::setSchedule(unique_ptr<Schedule> new_schedule)
  {
    schedule_ = std::move(new_schedule);
  }

  const Schedule& WorkDay::getSchedule() const
  {
    return *(schedule_.get());
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
