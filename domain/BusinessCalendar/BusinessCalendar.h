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
    bool findAndRemove(DateRepr const &date);
  public:
    BusinessCalendar() = default;
    ~BusinessCalendar();
    void addWorkDay(unique_ptr<WorkDay> work_day);
    bool removeWorkDay(DateRepr const &date);
    void fill(vector<unique_ptr<WorkDay>> &&work_days);
    WorkDay * findWorkDay(DateRepr const &date) const;

  };

} // namespace booksa
