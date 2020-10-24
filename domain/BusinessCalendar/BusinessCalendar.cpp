#include "BusinessCalendar.h"
#include "../Common/CustomContainers.h"
#include "../WorkDay/WorkDay.h"

using std::vector;
using std::unique_ptr;
using std::weak_ptr;

namespace booksa {

  BusinessCalendar::~BusinessCalendar(){

  }

  bool BusinessCalendar::addWorkDay(unique_ptr<WorkDay> rh_work_day)
  {
    return false;
  }

  bool BusinessCalendar::removeWorkDay(unique_ptr<WorkDay> rh_work_day)
  {
    return false;
  }

  weak_ptr<WorkDay> BusinessCalendar::findWorkDay(const DateRepr &date) const
  {
    return weak_ptr<WorkDay>();
  }

}
