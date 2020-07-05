//
// Created by cerussite on 7/5/20.
//

#pragma once

#include <utility>

namespace pyfunc {
namespace detail {

using std::begin;
using std::end;

template <class Container>
auto begin(Container&& c) -> decltype(begin(c)) {
  return begin(c);
}

template <class Container>
auto end(Container&& c) -> decltype(end(c)) {
  return end(c);
}

}  // namespace detail
}  // namespace pyfunc
