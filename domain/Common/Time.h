#ifndef TIME_H
#define TIME_H

namespace booksa {

  // WORK_UNIT_VAL in minutes default = 10
  const unsigned short int WORK_UNIT_VAL = 10;
  const unsigned short int UNITS_PER_DAY = 24 * 60 / WORK_UNIT_VAL;

  enum Month {
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

  enum WeekDay {
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
  };

} // namespace booksa

#endif // TIME_H
