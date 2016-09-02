
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(HasOnlyUniqueTest, TrueText) {
    EXPECT_TRUE(HasOnlyUnique("asd"));
}

TEST(HasOnlyUniqueTest, TrueSingleChar) {
    EXPECT_TRUE(HasOnlyUnique("a"));
}

TEST(HasOnlyUniqueTest, TrueEmpty) {
    EXPECT_TRUE(HasOnlyUnique(""));
}

TEST(HasOnlyUniqueTest, FalseText) {
    EXPECT_FALSE(HasOnlyUnique("Almafa"));
}
