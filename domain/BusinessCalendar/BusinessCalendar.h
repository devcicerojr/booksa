#ifndef BUSINESSCALENDAR_H
#define BUSINESSCALENDAR_H

#include "../Common/IEntity.h"
#include "../WorkDay/WorkDay.h"

#include <set>
#include <memory>
namespace booksa {

  class BusinessCalendar : IEntity
  {
  private:
    std::set<WorkDay> work_days_;
  public:
    BusinessCalendar();
    void addWorkDay(const WorkDay &work_day);
    void removeWorkDay(const WorkDay &work_day);
    const WorkDay* findWorkDay(const DateRepr &date) const;

  };

} // namespace booksa
#endif // BUSINESSCALENDAR_H
