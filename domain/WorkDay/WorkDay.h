#ifndef WORKDAY_H
#define WORKDAY_H
#include "../Common/IEntity.h"
// #include "../Common/Time.h"
#include "../Asset/Service.h"
#include <set>
#include <memory>


namespace booksa {

  class WorkDay : IEntity
  {
  private:
    bool is_holiday_ = false;
    std::set<std::shared_ptr<Service>> services_;

    TimeInterval open_time_{TimeRepr{DayHour::H08,MinuteVals::M00},
                            TimeRepr{DayHour::H18, MinuteVals::M00}};
    DateRepr date_;
  public:
    // 0 to 11
    WorkDay(const DateRepr &date);

    Day getDay() const;
    Month getMonth() const;
    Year getYear() const;

    bool operator <(const WorkDay &r_wd) const;
    bool operator >(const WorkDay &r_wd) const;
    bool operator ==(const WorkDay &r_wd) const;
    bool operator <=(const WorkDay &r_wd) const;
    bool operator >=(const WorkDay &r_wd) const;
    bool operator !=(const WorkDay &r_wd) const;


  };

} // namespace booksa
#endif // WORKDAY_H
