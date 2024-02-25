#include <gtest/gtest.h>

extern "C"
{
    #include "bin_tree.h"
    #include "search_alg.h"
}


// Demonstrate some basic assertions.
TEST(HelloTest, NumFactoredBinaryTrees) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  int arr[] = {1,2,3,4,5,6,7};
  numFactoredBinaryTrees(arr,7);
//   mis
}

TEST(HelloTest, MissingNumber) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  EXPECT_EQ(missingNumber(), 2);
//   mis
}
