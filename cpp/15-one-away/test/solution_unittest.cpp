
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(IsOneAwayTest, MissingChar) {
    EXPECT_TRUE(IsOneAway("ple", "pale"));
}

TEST(IsOneAwayTest, Typo) {
    EXPECT_TRUE(IsOneAway("bale", "pale"));
}

TEST(IsOneAwayTest, ExtraChar) {
    EXPECT_TRUE(IsOneAway("palle", "pale"));
}

TEST(IsOneAwayTest, MultipleMissing) {
    EXPECT_FALSE(IsOneAway("pe", "pale"));
}

TEST(IsOneAwayTest, MultipleTypo) {
    EXPECT_FALSE(IsOneAway("bake", "pale"));
}

TEST(IsOneAwayTest, MultipleExtra) {
    EXPECT_FALSE(IsOneAway("pallee", "pale"));
}

TEST(IsOneAwayTest, MissingTypo) {
    EXPECT_FALSE(IsOneAway("pla", "pale"));
}

TEST(IsOneAwayTest, TypoExtra) {
    EXPECT_FALSE(IsOneAway("palla", "pale"));
}
