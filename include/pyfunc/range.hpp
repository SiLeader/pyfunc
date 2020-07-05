//
// Created by cerussite on 7/3/20.
//

#pragma once

#include <utility>

namespace pyfunc {

namespace detail {

template <class I, class D>
class RangeIterator {
 private:
  I current_, last_;
  D diff_;
  bool is_valid_;

 public:
  RangeIterator() noexcept : current_(), last_(), diff_(), is_valid_(false) {}
  RangeIterator(I first, I last, D diff) noexcept
      : current_(std::move(first)),
        last_(std::move(last)),
        diff_(std::move(diff)),
        is_valid_(true) {}
  RangeIterator(const RangeIterator&) = default;
  RangeIterator(RangeIterator&&) noexcept = default;

  RangeIterator& operator=(const RangeIterator&) = default;
  RangeIterator& operator=(RangeIterator&&) noexcept = default;

 private:
  void next() {
    auto prev = current_;

    current_ += diff_;
    if (prev < current_) {
      if (!(current_ < last_)) {
        is_valid_ = false;
      }
    } else {
      if (!(last_ < current_)) {
        is_valid_ = false;
      }
    }
  }

 public:
  const I& operator*() const noexcept { return current_; }

  RangeIterator& operator++() {
    next();
    return *this;
  }

  const RangeIterator operator++(int) {
    auto c = *this;
    next();
    return c;
  }

  bool operator==(const RangeIterator& rhs) const noexcept {
    return is_valid_ == rhs.is_valid_;
  }
  bool operator!=(const RangeIterator& rhs) const noexcept {
    return !((*this) == rhs);
  }
};

template <class I = int, class D = int>
class Range {
 private:
  I first_, last_;
  D diff_;

 public:
  Range(I first, I last, D diff) noexcept
      : first_(std::move(first)),
        last_(std::move(last)),
        diff_(std::move(diff)) {}
  Range(I first, I last) noexcept
      : Range(std::move(first), std::move(last), D{1}) {}
  explicit Range(I last) noexcept : Range(I{}, std::move(last)) {}

  Range(const Range&) = default;
  Range(Range&&) noexcept = default;

  Range& operator=(const Range&) = default;
  Range& operator=(Range&&) noexcept = default;

 public:
  detail::RangeIterator<I, D> begin() const noexcept {
    return {first_, last_, diff_};
  }

  detail::RangeIterator<I, D> end() const noexcept { return {}; }
};

}  // namespace detail

template <class I>
detail::Range<I, I> range(I&& last) {
  return detail::Range<I, I>(std::forward<I>(last));
}

template <class I>
detail::Range<I, I> range(I&& first, I&& last) {
  return detail::Range<I, I>(std::forward<I>(first), std::forward<I>(last));
}

template <class I, class D>
detail::Range<I, D> range(I&& first, I&& last, D&& diff) {
  return detail::Range<I, D>(std::forward<I>(first), std::forward<I>(last),
                             std::forward<D>(diff));
}

}  // namespace pyfunc
