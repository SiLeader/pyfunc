//
// Created by cerussite on 7/4/20.
//

#include <gtest/gtest.h>

#include <pyfunc/enumerate.hpp>
#include <vector>

TEST(enumerate, enumerate_basic) {
  ::std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto ie : ::pyfunc::enumerate(vec)) {
    ::std::size_t i;
    int e;
    ::std::tie(i, e) = ie;

    EXPECT_EQ(i, e);
  }
}

TEST(enumerate, change_initial_count) {
  ::std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (auto ie : ::pyfunc::enumerate(vec, 1u)) {
    ::std::size_t i;
    int e;
    ::std::tie(i, e) = ie;

    EXPECT_EQ(i, e);
  }
}

TEST(enumerate, negative_initial_value) {
  std::vector<int> vec = {-2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for (auto ie : ::pyfunc::enumerate(vec, -2)) {
    int i;
    int e;
    ::std::tie(i, e) = ie;

    EXPECT_EQ(i, e);
  }
}
