#include "gtest/gtest.h"
#include <iostream>
#include "base.hpp"
#include "div.h"
#include "pow.h"
#include "add.h"
#include "op.hpp"
#include "sub.h"
#include "rand.h"
#include "mult.h"
#include "visitor.hpp"
#include "iterator.hpp"
#include "iterator_tests.h"


// #include "op_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
