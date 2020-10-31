#pragma once

#include "../Common/IEntity.h"
#include "../Common/Time.h"
#include <map>
#include <memory>

namespace booksa {
  using std::multimap;
  using std::shared_ptr;
  class Service;

  typedef std::pair<TimeInterval,shared_ptr<Service>> ScheduleItem;

  class Service;

  class Schedule : IEntity {

  private:

    multimap <TimeInterval,shared_ptr<Service>> services_scheduled_;

  public:

    Schedule() = default;
    TimeInterval getTimeInterval() const;
    void setTimeInterval(TimeInterval &new_time_interval);

    void add(ScheduleItem &&sch_item);
    void remove(ScheduleItem &sch_item);

  };

} // namespace booksa
