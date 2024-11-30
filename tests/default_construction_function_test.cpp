#include <gtest/gtest.h>

#include "Executor.hpp"
#include "Point.hpp"
using namespace car;
TEST(Executor, Executor_return_default__Test)
{
    Executor executor;
    EXPECT_EQ(executor.getPosition(), Point(0, 0));
    EXPECT_EQ(executor.getDirection(), 'N');
}