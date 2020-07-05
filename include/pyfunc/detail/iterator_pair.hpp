//
// Created by cerussite on 7/3/20.
//

#pragma once

#include <utility>

namespace pyfunc::detail {

template <class FirstIterator, class LastIterator>
class IteratorPair {
 private:
  FirstIterator first_;
  LastIterator last_;

 public:
  IteratorPair(FirstIterator first, LastIterator last)
      : first_(std::move(first)), last_(std::move(last)) {}

 public:
  FirstIterator begin() const { return first_; }
  LastIterator end() const { return last_; }
};

}  // namespace pyfunc::detail
