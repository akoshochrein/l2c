
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(IsPalindromePermutationTest, SuccessOdd) {
    EXPECT_TRUE(IsPalindromePermutation("Tact Coa"));
}

TEST(IsPalindromePermutationTest, SuccessEven) {
    EXPECT_TRUE(IsPalindromePermutation("A but tuba"));
}

TEST(IsPalindromePermutationTest, SuccessComplex) {
    EXPECT_TRUE(IsPalindromePermutation("Are we not drawn onward, we few, drawn onward to new era"));
}

TEST(IsPalindromePermutationTest, Failure) {
    EXPECT_FALSE(IsPalindromePermutation("A Taco Cat"));
}

TEST(IsPalindromePermutationTest, Empty) {
    EXPECT_TRUE(IsPalindromePermutation(""));
}
