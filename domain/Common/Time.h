#ifndef TIME_H
#define TIME_H

namespace booksa {

  // MINUTE_UNIT in minutes default = 10
  const unsigned short int MINUTE_UNIT = 5;
  const unsigned short int MINUTE_INTERVALS = 24 * 60 / MINUTE_UNIT;

  struct Year {
    unsigned int year;
    bool operator <(const Year &r_year) const{
      return (year < r_year.year);
    }
    bool operator >(const Year &r_year) const{
      return (year > r_year.year);
    }
    bool operator ==(const Year &r_year) const{
      return (year == r_year.year);
    }
    bool operator >=(const Year &r_year) const {
      return (year >= r_year.year);
    }
    bool operator <=(const Year &r_year) const {
      return (year <= r_year.year);
    }
    bool operator !=(const Year &r_year) const {
      return (year != r_year.year);
    }
  };


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

  enum Day {
    D01 = 1,
    D02,
    D03,
    D04,
    D05,
    D06,
    D07,
    D08,
    D09,
    D10,
    D11,
    D12,
    D13,
    D14,
    D15,
    D16,
    D17,
    D18,
    D19,
    D20,
    D21,
    D22,
    D23,
    D24,
    D25,
    D26,
    D27,
    D28,
    D29,
    D30,
    D31
  };

  struct DateRepr
  {
    Day day;
    Month month;
    Year year;
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

  enum DayHour {
    H00,
    H01,
    H02,
    H03,
    H04,
    H05,
    H06,
    H07,
    H08,
    H09,
    H10,
    H11,
    H12,
    H13,
    H14,
    H15,
    H16,
    H17,
    H18,
    H19,
    H20,
    H21,
    H22,
    H23
  };

  enum MinuteVals {
    M00,
    M05,
    M10,
    M15,
    M20,
    M25,
    M30,
    M35,
    M40,
    M45,
    M50,
    M55
  };

  struct TimeRepr {
    DayHour hour;
    MinuteVals minute;
    bool operator <(const TimeRepr &r_val) const{
      if(hour < r_val.hour)
        return true;
      if(hour == r_val.hour &&
         minute < r_val.minute)
        return true;
      return false;
    }

    bool operator >(const TimeRepr &r_val) const {
      if(hour > r_val.hour)
        return true;
      if(hour == r_val.hour &&
         minute > r_val.minute)
        return true;
      return false;
    }

    bool operator ==(const TimeRepr &r_val) const {
      if(hour == r_val.hour &&
         minute == r_val.minute)
        return true;
      return false;
    }

    bool operator <=(const TimeRepr &r_val) const {
      return !(*this > r_val);
    }

    bool operator >=(const TimeRepr &r_val) const {
      return !(*this < r_val);
    }

    bool operator !=(const TimeRepr &r_val) const {
      return !(*this == r_val);
    }


  };

  struct TimeInterval {
    TimeRepr begin;
    TimeRepr end;
    TimeInterval(const TimeRepr &r_begin, const TimeRepr &r_end) :
    begin(r_begin <= r_end ? r_begin : r_end),
    end(r_end){
      if(r_begin > r_end) {
        begin = r_end;
        end = r_begin;
      }
    }

  };

} // namespace booksa

#endif // TIME_H
