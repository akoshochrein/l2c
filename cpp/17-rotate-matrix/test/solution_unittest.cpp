
#include <limits.h>
#include <vector>
#include "../src/solution.h"
#include "gtest/gtest.h"

TEST(RotateMatrix, Success3x3) {
    std::vector<std::vector<int> > toRotate = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int> > expected = {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };
    EXPECT_EQ(
        expected,
        RotateMatrix(toRotate)
    );
}

TEST(RotateMatrix, Success4x4) {
    std::vector<std::vector<int> > toRotate = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
    };
    std::vector<std::vector<int> > expected = {
        { 4,  8, 12, 16},
        { 3,  7, 11, 15},
        { 2,  6, 10, 14},
        { 1,  5,  9, 13},
    };
    EXPECT_EQ(
        expected,
        RotateMatrix(toRotate)
    );
}

TEST(RotateMatrix, Success5x5) {
    std::vector<std::vector<int> > toRotate = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    std::vector<std::vector<int> > expected = {
        { 5, 10, 15, 20, 25},
        { 4,  9, 14, 19, 24},
        { 3,  8, 13, 18, 23},
        { 2,  7, 12, 17, 22},
        { 1,  6, 11, 16, 21},
    };
    EXPECT_EQ(
        expected,
        RotateMatrix(toRotate)
    );
}
