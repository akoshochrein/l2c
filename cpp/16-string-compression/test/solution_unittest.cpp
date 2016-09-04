
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(CompressTest, SuccessLong) {
    EXPECT_EQ("a3b3c3", Compress("aaabbbccc"));
}

TEST(CompressTest, SuccessShort) {
    EXPECT_EQ("alma", Compress("alma"));
}

TEST(CompressTest, Empty) {
    EXPECT_EQ("", Compress(""));
}

TEST(CompressTest, Standard) {
    EXPECT_EQ("a3b1c5a2", Compress("aaabcccccaa"));
}
