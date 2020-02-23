#ifndef WORKDAY_H
#define WORKDAY_H
#include "../Common/IEntity.h"
#include "../Asset/Service.h"
#include <set>


namespace booksa {

// WORK_UNIT_VAL in minutes default = 10
  const unsigned short int WORK_UNIT_VAL = 10;
  const unsigned short int UNITS_PER_DAY = 24 * 60 / WORK_UNIT_VAL;

  enum Months {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
  };

  enum WeekDays {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
  };

  class WorkDay : IEntity
  {
  private:
    std::set<Service*> services_;
  public:
    WorkDay();
  };

} // namespace booksa
#endif // WORKDAY_H
