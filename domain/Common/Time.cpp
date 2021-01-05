#include "Time.h"

unsigned int numberOfDays (unsigned int month, int year)
{
  switch(month) {
    // invalid
  case 0:
    return 0;
    break;
    // january
  case 1:
    return 31;
    break;
    // february
  case 2:
    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0))
      return 29;
    else
      return 28;
    break;
    // march
  case 3:
    return 31;
    break;
    // april
  case 4:
    return 30;
    break;
    // may
  case 5:
    return 31;
    break;
    // june
  case 6:
    return 30;
    break;
    // july
  case 7:
    return 31;
    break;
  case 8:
    // august
    return 31;
    break;
    // september
  case 9:
    return 30;
    break;
    // october
  case 10:
    return 31;
    break;
    // november
  case 11:
    return 30;
    break;
    // december
  case 12:
  default:
    return 31;
    break;
  }
}

bool isDateValid(unsigned int day, unsigned int month, unsigned int year) {
  if (day <= numberOfDays(month, year) &&
      day > 0 &&
      month > 0 &&
      year > 0) {
    return true;
  }

  return false;
}

int dayNumber (unsigned int day, unsigned int month, unsigned int year) {

  if (! isDateValid(day, month, year)) return false;

  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

  year -= month < 3;
  return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;

}

std::string getMonthName(int monthNumber)
{
    std::string months[] = {"January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
                      };

    return (months[monthNumber]);
}
