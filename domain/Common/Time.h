#pragma once
#include <utility>
#include <string>

namespace booksa {

  using std::string;

  // MINUTE_UNIT in minutes default = 10
  unsigned short int const MINUTE_UNIT = 5;
  unsigned short int const MINUTE_INTERVALS = 24 * 60 / MINUTE_UNIT;



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
    Year(unsigned int yr) : year(yr) {}
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
    DateRepr(Day d=D01, Month m=JANUARY, Year y=0):
      day(d),
      month(m),
      year(y){}

    bool operator<(const DateRepr &rh_date) const {
      if(year < rh_date.year)
        return true;
      if(year == rh_date.year) {
        if(month < rh_date.month)
          return true;
      }
      if(year == rh_date.year && month == rh_date.month) {
        if(day < rh_date.day)
          return true;
      }
      return false;
    }

    bool operator>(const DateRepr &rh_date) const {
      if(year > rh_date.year)
        return true;
      if(year == rh_date.year) {
        if(month > rh_date.month)
          return true;
      }
      if(year == rh_date.year && month == rh_date.month) {
        if(day > rh_date.day)
          return true;
      }
      return false;
    }

    bool operator==(const DateRepr &rh_date) const {
      if(year == rh_date.year &&
         month == rh_date.month &&
         day == rh_date.day)
        return true;
      return false;
    }

    bool operator!=(const DateRepr &rh_date) const {
      return (*this == rh_date);
    }

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
    M00, M01, M02, M03, M04, M05, M06, M07, M08, M09,
    M10, M11, M12, M13, M14, M15, M16, M17, M18, M19,
    M20, M21, M22, M23, M24, M25, M26, M27, M28, M29,
    M30, M31, M32, M33, M34, M35, M36, M37, M38, M39,
    M40, M41, M42, M43, M44, M45, M46, M47, M48, M49,
    M50, M51, M52, M53, M54, M55, M56, M57, M58, M59
  };

  struct TimeRepr {
    DayHour hour = H00;
    MinuteVals minute = M00;
    bool operator < (const TimeRepr &r_val) const {
      if (hour < r_val.hour)
        return true;
      if (hour == r_val.hour && minute < r_val.minute )
        return true;

      return false;
    }

    bool operator > (const TimeRepr &r_val) const {
      if (hour > r_val.hour)
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
    TimeRepr begin_;
    TimeRepr end_;
    TimeInterval(TimeRepr const &r_begin, TimeRepr const &r_end)
    {
      if(r_begin > r_end) {
        begin_ = r_end;
        end_ = r_begin;
      } else {
        begin_ = r_begin;
        end_ = r_end;
      }
    }

    TimeInterval(TimeInterval const &rh_timeInt) {
      begin_ = rh_timeInt.begin_;
      end_ = rh_timeInt.end_;
    }

    TimeInterval(TimeInterval &&rh_timeInt) {
      begin_ = std::move(rh_timeInt.begin_);
      end_ = std::move(rh_timeInt.end_);
    }

    TimeInterval& operator = (TimeInterval const &rh_timeInt) {
      begin_ = rh_timeInt.begin_;
      end_ = rh_timeInt.end_;
      return *this;
    }

    TimeInterval& operator = (TimeInterval &&rh_timeInt) {
      if(this != &rh_timeInt) {
        begin_ = std::move(rh_timeInt.begin_);
        end_ = std::move(rh_timeInt.end_);
      }
      return *this;
    }

    bool operator < (TimeInterval const &rh_t) const {
      if (begin_ < rh_t.begin_)
        return true;
      else if (begin_ == rh_t.begin_ && end_ < rh_t.end_) {
        return true;
      }
      return false;
    }

  };

//-------------------------------------------------------------------

  unsigned int numberOfDays (unsigned int month, int year);

  bool isDateValid(unsigned int day, unsigned int month, unsigned int year);

  int dayNumber (unsigned int day, unsigned int month, unsigned int year);

  string getMonthName(int monthNumber);



  // Function to print the calendar of the given year
//  void printCalendar(int year)
//  {
//      printf ("         Calendar - %d\n\n", year);
//      int days;

//      // Index of the day from 0 to 6
//      int current = dayNumber (1, 1, year);

//      // i --> Iterate through all the months
//      // j --> Iterate through all the days of the
//      //       month - i
//      for (int i = 0; i < 12; i++)
//      {
//          days = numberOfDays (i, year);

//          // Print the current month name
//          printf("\n  ------------%s-------------\n",
//                 getMonthName (i).c_str());

//          // Print the columns
//          printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

//          // Print appropriate spaces
//          int k;
//          for (k = 0; k < current; k++)
//              printf("     ");

//          for (int j = 1; j <= days; j++)
//          {
//              printf("%5d", j);

//              if (++k > 6)
//              {
//                  k = 0;
//                  printf("\n");
//              }
//          }

//          if (k)
//              printf("\n");

//          current = k;
//      }

//      return;
//  }

} // namespace booksa

