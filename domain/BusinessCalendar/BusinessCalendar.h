#ifndef BUSINESSCALENDAR_H
#define BUSINESSCALENDAR_H

#include "../Common/IEntity.h"
#include "../WorkDay/WorkDay.h"

#include <set>
#include <memory>

using std::unique_ptr;

namespace booksa {


  struct WorkDayHandle {
  private:
    DateRepr date;
  public:
    unique_ptr<WorkDay> wd_ptr;
    WorkDayHandle() = default;
    explicit WorkDayHandle(std::unique_ptr<WorkDay> wd):
      wd_ptr{std::move(wd)},
      date(D01, JANUARY, 0)
    {
      if(wd_ptr)
        date = wd_ptr->getDate();
    }

    WorkDayHandle(WorkDayHandle &&rh_wdh) {

      wd_ptr = std::move(rh_wdh.wd_ptr);
      if(wd_ptr)
        date = wd_ptr->getDate();
    }

    bool setDate(const DateRepr _date) {
      if(!wd_ptr) {
        date = _date;
        return true;
      }
      // can't set date if wd_ptr is valid
      return false;
    }
    const DateRepr& getDate() const {
      return date;
    }

    bool operator<(const WorkDayHandle& rh_wdh) const {
      return date < rh_wdh.getDate() ? true : false;
    }

    bool operator==(const WorkDayHandle& rh_wdh) const {
      return (date == rh_wdh.getDate()) ? true : false;
    }

    WorkDayHandle(const WorkDayHandle& wdh) {
      WorkDay* cp_wdp = nullptr;
      if(wdh.wd_ptr) {
        wd_ptr = std::make_unique<WorkDay>(*(wdh.wd_ptr.get()));
        date = wd_ptr->getDate();
      }
    }

    WorkDayHandle& operator=(const WorkDayHandle& rh_wdh) {
      WorkDay* cp_wdp = nullptr;
      wd_ptr.reset();
      if(rh_wdh.wd_ptr) {
        wd_ptr = std::make_unique<WorkDay>(*(rh_wdh.wd_ptr.get()));
        date = wd_ptr->getDate();
      }
      else {
        date = rh_wdh.getDate();
      }
    }
  };

  class BusinessCalendar : IEntity
  {
  private:
    std::vector<WorkDayHandle> work_days_;
  public:
    BusinessCalendar();
    void addWorkDay(unique_ptr<WorkDay> work_day);
    void removeWorkDay(const WorkDayHandle &wd_handle);
    const WorkDay* findWorkDay(const DateRepr &date) const;

  };

} // namespace booksa
#endif // BUSINESSCALENDAR_H
