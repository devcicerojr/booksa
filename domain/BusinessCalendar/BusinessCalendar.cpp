#include "BusinessCalendar.h"
#include "../Common/CustomContainers.h"

namespace booksa {

  BusinessCalendar::BusinessCalendar() :
    IEntity(0)
  {

  }

  void BusinessCalendar::addWorkDay(unique_ptr<WorkDay> work_day) {
    WorkDayHandle wdh(std::move(work_day));
    insert_sorted<WorkDayHandle>(work_days_, wdh);
    std::vector<WorkDayHandle>::iterator last_uniq_it = std::unique(work_days_.begin(), work_days_.end());
    work_days_.erase(last_uniq_it, work_days_.end());
  }

  void BusinessCalendar::removeWorkDay(const WorkDayHandle& wd_handle) {
    auto it = std::lower_bound(work_days_.begin(), work_days_.end(), wd_handle);
    if (it != work_days_.end())
      work_days_.erase(it);
  }

  const WorkDay* BusinessCalendar::findWorkDay(const DateRepr &date) const {
    WorkDay* wd_retval = nullptr;
    WorkDayHandle wd_handle;
    wd_handle.setDate(date);
    auto it = std::lower_bound(work_days_.begin(), work_days_.end(), wd_handle);
    if (it != work_days_.end())
      return (*it).wd_ptr.get();
  }

} // namespace booksa
