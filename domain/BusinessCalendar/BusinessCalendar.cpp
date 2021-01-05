#include "BusinessCalendar.h"
#include "../Common/CustomContainers.h"
#include "../WorkDay/WorkDay.h"
#include <algorithm>

using std::vector;
using std::unique_ptr;
using std::weak_ptr;
using std::begin;
using std::end;

namespace booksa {

  bool BusinessCalendar::findAndRemove(const DateRepr &date)
  {
    auto found = std::remove_if(begin(work_days_), end(work_days_),
                              [&](unique_ptr<WorkDay> const &elem){
        return (elem->getDate() == date) ? true : false ;

    });

    if (found != end(work_days_)) {
        work_days_.erase(found, end(work_days_));
        return true;
    }

    return false;
  }

  BusinessCalendar::~BusinessCalendar(){

  }

  void BusinessCalendar::addWorkDay(unique_ptr<WorkDay> work_day)
  {
    unq_insert_sorted(work_days_, std::move(work_day));
  }

  bool BusinessCalendar::removeWorkDay(const DateRepr &date)
  {
    return findAndRemove(date);
  }

  void BusinessCalendar::fill(vector<unique_ptr<WorkDay> > &&work_days)
  {
    work_days_.clear();
    work_days_ = std::move(work_days);
  }

  WorkDay * BusinessCalendar::findWorkDay(const DateRepr &date) const
  {
    auto found = std::find_if(begin(work_days_), end(work_days_),
                              [&](unique_ptr<WorkDay> const &elem){
        return (elem->getDate() == date) ? true : false ;

    });

    return found != end(work_days_) ? (*found).get() : nullptr;
  }

}
