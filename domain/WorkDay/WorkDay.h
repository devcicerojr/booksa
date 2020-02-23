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

  public:
    // 0 to 11
    unsigned short int getMonth() const;
    WorkDay();
  };

} // namespace booksa
#endif // WORKDAY_H
