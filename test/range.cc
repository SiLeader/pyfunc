//
// Created by cerussite on 7/3/20.
//

#include <gtest/gtest.h>

#include <pyfunc/range.hpp>

TEST(range, range10) {
  int counter = 0;
  for (const auto i : ::pyfunc::range(10)) {
    EXPECT_EQ(counter, i);
    counter++;
  }
  EXPECT_EQ(counter, 10);
}

TEST(range, range1_10) {
  int counter = 1;
  for (const auto i : ::pyfunc::range(1, 10)) {
    EXPECT_EQ(counter, i);
    counter++;
  }
  EXPECT_EQ(counter, 10);
}

TEST(range, range1_11_2) {
  int counter = 1;
  for (const auto i : ::pyfunc::range(1, 11, 2)) {
    EXPECT_EQ(counter, i);
    counter += 2;
  }
  EXPECT_EQ(counter, 11);
}

TEST(range, range1_10_dec) {
  int counter = 10;
  for (const auto i : ::pyfunc::range(10, 1, -1)) {
    EXPECT_EQ(counter, i);
    counter--;
  }
  EXPECT_EQ(counter, 1);
}
