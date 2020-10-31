#pragma once

#include "../Common/IEntity.h"
#include "../Common/Time.h"

#include <set>
#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;
using std::weak_ptr;

namespace booksa {

  class WorkDay;

  class BusinessCalendar : IEntity
  {
  private:
    // this vector should be kept ordered and without duplicates (set?)
    vector<unique_ptr<WorkDay>> work_days_{};
  public:
    BusinessCalendar() = default;
    ~BusinessCalendar();
    bool addWorkDay(unique_ptr<WorkDay> rh_work_day);
    bool removeWorkDay(unique_ptr<WorkDay> rh_work_day);
    weak_ptr<WorkDay> findWorkDay(DateRepr const &date) const;

  };

} // namespace booksa
