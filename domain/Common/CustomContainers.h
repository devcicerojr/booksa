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



    template <typename T>
    typename std::vector<T>::iterator
    unq_insert_sorted( std::vector<T> &vec, T &&item )
    {
      return vec.emplace
          (
            std::upper_bound( vec.begin(), vec.end(), item,
                              [](T const &elem, T const &item ){
              return *elem > *item;
            }),
            std::move(item)
            );
    }
} // namespace booksa

#endif // CUSTOMCONTAINERS_H
