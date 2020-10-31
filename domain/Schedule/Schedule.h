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

    void add(ScheduleItem &&sch_item);
    void remove(ScheduleItem &sch_item);
    void intervalCap(TimeInterval const &cap_interval);

  };

} // namespace booksa
