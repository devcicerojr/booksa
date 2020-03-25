#include "BusinessCalendar.h"

namespace booksa {

  BusinessCalendar::BusinessCalendar() :
    IEntity(0)
  {

  }

  void BusinessCalendar::addWorkDay(const WorkDay &work_day) {
    work_days_.insert(work_day);
  }
  void BusinessCalendar::removeWorkDay(const WorkDay &work_day) {
    auto it = work_days_.find(work_day);
    if(it != work_days_.end())
      work_days_.erase(it);
  }

  const WorkDay* BusinessCalendar::findWorkDay(const DateRepr &date) const {
    const WorkDay *work_d;
    WorkDay wd(date);
    auto it = work_days_.find(wd);
    if(it != work_days_.end())
      work_d = &*it;
    return work_d;
  }

} // namespace booksa
