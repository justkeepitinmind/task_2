#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"

using namespace car;
TEST(Executor, ExecutorImpl_move_Test)
{
    ExecutorImpl executor(Point{5, 2}, 'N');
    executor.execute("M");
    EXPECT_EQ(executor.getPosition(), Point(5, 3));
    // EXPECT_EQ(executor.getDirection(), 'N');
}