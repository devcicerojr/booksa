#pragma once
#include "../Common/IEntity.h"
#include "../Common/Time.h"
#include <vector>
#include <memory>


namespace booksa {

  using std::vector;
  using std::shared_ptr;
  using std::unique_ptr;

  class Schedule;
  class Service;

  class WorkDay : IEntity
  {
  private:
    bool is_holiday_ = false;
    DateRepr date_;
    TimeInterval working_time_{TimeRepr{DayHour::H06,MinuteVals::M00},
                            TimeRepr{DayHour::H22, MinuteVals::M00}};

    unique_ptr<Schedule> schedule_;

  public:
    // 0 to 11
    WorkDay(const DateRepr &date);

    Day getDay() const;
    Month getMonth() const;
    Year getYear() const;
    DateRepr getDate() const;

    void addToSchedule(shared_ptr<Service> service , TimeInterval const &t_interval);
    void removeFromSchedule(shared_ptr<Service> service, TimeInterval const &t_interval);

    void setHoliday(bool val);
    bool isHoliday() const;

    void setWorkingTime(TimeInterval const &new_wt);
    TimeInterval getWorkingTime() const ;

    bool operator <(const WorkDay &r_wd) const;
    bool operator >(const WorkDay &r_wd) const;
    bool operator ==(const WorkDay &r_wd) const;
    bool operator <=(const WorkDay &r_wd) const;
    bool operator >=(const WorkDay &r_wd) const;
    bool operator !=(const WorkDay &r_wd) const;


  };

} // namespace booksa
