#include "Business.h"

namespace booksa {

  Business::Business(const BusinessCalendar &calendar):
  IEntity(0)
  {
    calendar_ = calendar;
  }



} // namespace booksa
