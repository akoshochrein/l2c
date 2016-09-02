PROBLEM_NAME=$1

mkdir $PROBLEM_NAME
cd $PROBLEM_NAME

# Create source files
mkdir src
touch main.h
ehco '''
#include <iostream>

#include "main.h"

using namespace std;

int main () {
    return 0;
}
''' >> main.cpp

# Create test files
mkdir test
echo '''
#include <limits.h>
#include "../src/main.h"
#include "gtest/gtest.h"

// TEST(HasOnlyUniqueTest, TrueText) {
//     EXPECT_TRUE(HasOnlyUnique("asd"));
// }
''' >> main_unittest.cpp

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

test: $(TESTS)

clean :
	rm -f $(TESTS) gtest.a gtest_main.a *.o

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

# Main Test

main.o : $(USER_SRC_DIR)/main.cpp $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_SRC_DIR)/main.cpp

main_unittest.o : $(USER_TEST_DIR)/main_unittest.cpp \
                     $(USER_SRC_DIR)/main.h $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(USER_TEST_DIR)/main_unittest.cpp

main_unittest : main.o main_unittest.o gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(USER_BIN_DIR)/$@
''' >> Makefile
