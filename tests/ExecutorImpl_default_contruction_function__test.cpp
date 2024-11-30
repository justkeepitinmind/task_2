#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"

using namespace car;
TEST(Executor, ExecutorImpl_default_construction_function_Test)
{
    ExecutorImpl executor;
    EXPECT_EQ(executor.getPosition(), Point(0, 0));
    EXPECT_EQ(executor.getDirection(), 'N');
}
