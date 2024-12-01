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
    executor.execute("L");
    EXPECT_EQ(executor.getPosition(), Point(8, 2));
    EXPECT_EQ(executor.getDirection(), 'N');

    executor.execute("R");
    EXPECT_EQ(executor.getPosition(), Point(8, 3));
    EXPECT_EQ(executor.getDirection(), 'E');

    executor.execute("FM");
    EXPECT_EQ(executor.getPosition(), Point(9, 3));
}