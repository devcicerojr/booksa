#ifndef CUSTOMCONTAINERS_H
#define CUSTOMCONTAINERS_H

#include <vector>
#include <algorithm>

namespace booksa {

    template <typename T>
    typename std::vector<T>::iterator
    insert_sorted( std::vector<T> & vec, T const& item )
    {
      return vec.insert
          (
            std::upper_bound( vec.begin(), vec.end(), item ),
            item
            );
    }
} // namespace booksa

#endif // CUSTOMCONTAINERS_H
