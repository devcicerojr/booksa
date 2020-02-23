#ifndef BUSINESSCALENDAR_H
#define BUSINESSCALENDAR_H
#include "../Common/IEntity.h"
#include "../WorkDay/WorkDay.h"
#include <set>

namespace booksa {

  class BusinessCalendar : IEntity
  {
  private:
    std::set<WorkDay*> work_days_;
  public:
    BusinessCalendar();
    BusinessCalendar(unsigned long int id);
  };

} // namespace booksa

#endif // BUSINESSCALENDAR_H
