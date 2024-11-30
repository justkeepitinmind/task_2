#include <gtest/gtest.h>

#include "Executor.hpp"
#include "Point.hpp"
using namespace car;
TEST(Executor, Executor_Turn_Left_Test)
{
    Executor executor({2, 5}, 'S');
    EXPECT_EQ(executor.get_directions(), 'S');

    executor.execute("L");
    EXPECT_EQ(executor.get_directions(), 'E');

    executor.execute("L");
    EXPECT_EQ(executor.get_directions(), 'N');

    executor.execute("L");
    EXPECT_EQ(executor.get_directions(), 'W');

    executor.execute("L");
    EXPECT_EQ(executor.get_directions(), 'S');
}