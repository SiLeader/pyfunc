//
// Created by cerussite on 7/3/20.
//

#pragma once

#include <cstddef>
#include <iterator>

#include "detail/iterator_pair.hpp"
#include "detail/utility.hpp"

namespace pyfunc {

namespace detail {

template <class Iterator, class Counter = std::size_t>
class EnumerateIterator {
 public:
  using defference_type =
      typename std::iterator_traits<Iterator>::difference_type;
  using value_type = typename std::iterator_traits<Iterator>::value_type;
  using pointer = typename std::iterator_traits<Iterator>::pointer;
  using reference = typename std::iterator_traits<Iterator>::reference;

 private:
  Iterator iterator_;
  Counter counter_;

 public:
  EnumerateIterator(Iterator itr, Counter counter) noexcept
      : iterator_(std::move(itr)), counter_(counter) {}
  explicit EnumerateIterator(Iterator itr) noexcept
      : EnumerateIterator(std::move(itr), 0) {}

  EnumerateIterator(const EnumerateIterator&) = default;
  EnumerateIterator(EnumerateIterator&&) noexcept = default;

  EnumerateIterator& operator=(const EnumerateIterator&) = default;
  EnumerateIterator& operator=(EnumerateIterator&&) noexcept = default;

 public:
  std::tuple<Counter, value_type&> operator*() {
    return {counter_, *iterator_};
  }
  std::tuple<Counter, const value_type&> operator*() const {
    return {counter_, *iterator_};
  }

 public:
  EnumerateIterator& operator++() {
    ++iterator_;
    ++counter_;
    return *this;
  }

  const EnumerateIterator operator++(int) {
    auto c = *this;
    ++(*this);
    return c;
  }

 public:
  bool operator==(const EnumerateIterator& rhs) const {
    return iterator_ == rhs.iterator_;
  }

  bool operator!=(const EnumerateIterator& rhs) const {
    return !((*this) == rhs);
  }
};

}  // namespace detail

template <class Container, class Counter = std::size_t>
auto enumerate(Container&& container, Counter start = 0)
    -> detail::IteratorPair<
        detail::EnumerateIterator<decltype(detail::begin(container))>,
        detail::EnumerateIterator<decltype(detail::end(container))>> {
  return {{detail::begin(container), start}, {detail::end(container), start}};
}

}  // namespace pyfunc
