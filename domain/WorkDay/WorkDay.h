#ifndef WORKDAY_H
#define WORKDAY_H
#include "../Common/IEntity.h"
// #include "../Common/Time.h"
#include "../Asset/Service.h"
#include <set>


namespace booksa {

  class WorkDay : IEntity
  {
  private:

    bool is_holiday_ = false;
    std::set<Service*> services_;

    TimeInterval open_time_{TimeRepr{DayHour::H08,MinuteVals::M00},
                             TimeRepr{DayHour::H18, MinuteVals::M00}};

  public:
    // 0 to 11
    Month getMonth() const;
    Day getDay() const;
    WeekDay getWeekDay() const;


    WorkDay();
  };

} // namespace booksa
#endif // WORKDAY_H