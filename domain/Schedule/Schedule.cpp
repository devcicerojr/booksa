#include "Schedule.h"
#include <algorithm>

namespace booksa {
  using std::remove_if;

  Schedule::Schedule(Schedule &&rh_sch)
  {
    services_scheduled_ = std::move(rh_sch.services_scheduled_);
  }

  Schedule &Schedule::operator =(Schedule &&rh_sch)
  {
    if (this != &rh_sch) {
      services_scheduled_ = std::move(rh_sch.services_scheduled_);
    }
    return *this;
  }

  void Schedule::add(ScheduleItem &&sch_item)
  {
    services_scheduled_.insert(std::move(sch_item));
  }

  void Schedule::remove(ScheduleItem &sch_item)
  {
    services_scheduled_.erase(sch_item.first);
  }

  void Schedule::intervalCap(TimeInterval const &cap_interval)
  {
    // standard associative-container erase idiom
    for (auto it = begin(services_scheduled_); it != end(services_scheduled_);)
    {
      if ( (*it).first.begin_ < cap_interval.begin_ ||
           (*it).first.end_ > cap_interval.end_ ) {
        services_scheduled_.erase(it++);
      }
      else {
        ++it;
      }
    }
  }

}
