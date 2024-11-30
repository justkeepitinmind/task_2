#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"

using namespace car;
TEST(Executor, ExecutorImpl_changeSpeed_Test)
{
    ExecutorImpl executor(Point{5, 2}, 'E');
    executor.execute("FM");
    EXPECT_EQ(executor.getPosition(), Point(7, 2));
    // EXPECT_EQ(executor.getDirection(), 'N');
    executor.execute("FM");
    EXPECT_EQ(executor.getPosition(), Point(8, 2));
}