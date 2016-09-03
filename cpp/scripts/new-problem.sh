PROBLEM_NAME=$1

mkdir $PROBLEM_NAME
cd $PROBLEM_NAME

# Create source files
mkdir src
touch src/solution.h
touch src/solution.cpp
echo '''
#include <iostream>

#include "solution.h"

using namespace std;

int main () {
    return 0;
}
''' >> src/main.cpp

# Create test files
mkdir test
echo '''
#include <limits.h>
#include "../src/solution.h"
#include "gtest/gtest.h"

// TEST(HasOnlyUniqueTest, TrueText) {
//     EXPECT_TRUE(HasOnlyUnique("asd"));
// }
''' >> test/main_unittest.cpp

# Create bin
mkdir bin

# Create makefile
echo '''
GTEST_DIR = ../googletest

USER_SRC_DIR = src
USER_TEST_DIR = test
USER_BIN_DIR = bin

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread

TESTS = main_unittest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

all : main

sol: main

test: $(TESTS)
    ./bin/$(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o
    rm -rf $(USER_BIN_DIR)/*

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

main :
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(USER_SRC_DIR)/main.cpp $(USER_SRC_DIR)/solution.cpp -o $(USER_BIN_DIR)/$@

solution.o : $(USER_SRC_DIR)/solution.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_SRC_DIR)/solution.cpp

solution_unittest.o : $(USER_TEST_DIR)/solution_unittest.cpp \
                     $(USER_SRC_DIR)/solution.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_TEST_DIR)/solution_unittest.cpp

solution_unittest : main.o solution_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(USER_BIN_DIR)/$@
''' >> Makefile
