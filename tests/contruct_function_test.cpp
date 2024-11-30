#include <gtest/gtest.h>

#include "Executor.hpp"
#include "Point.hpp"
using namespace car;
TEST(Executor, Executor_contruction_Test)
{
    Executor executor({2, 5}, 'S');
    EXPECT_EQ(executor.get_position(), Point(2, 5));
    EXPECT_EQ(executor.get_directions(), 'S');
}