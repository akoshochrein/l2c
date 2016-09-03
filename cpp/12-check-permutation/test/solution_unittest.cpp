
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(ArePermutationsTest, Permutations) {
    EXPECT_TRUE(ArePermutations("rat", "tar"));
}

TEST(ArePermutationsTest, PermutationsLonger) {
    EXPECT_TRUE(ArePermutations("tie sent ring", "green tin sit"));
}

TEST(ArePermutationsTest, CapsMatter) {
    EXPECT_FALSE(ArePermutations("this", "HITS"));
}

TEST(ArePermutationsTest, Empty) {
    EXPECT_TRUE(ArePermutations("", ""));
}

TEST(ArePermutationsTest, DifferentLength) {
    EXPECT_FALSE(ArePermutations("Mayonaise", "Ketchup"));
}

TEST(ArePermutationsTest, ArentPermutations) {
    EXPECT_FALSE(ArePermutations("cat", "car"));
}
