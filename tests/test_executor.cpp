#include <gtest/gtest.h>

#include "Executor.h"
#include "point.h"
TEST(Executor, test_case)
{
    Executor executor(point{0, 4}, 'N');
    EXPECT_EQ(executor.get_position().x, 0);
    EXPECT_EQ(executor.get_position().y, 4);
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("MMMM");
    EXPECT_EQ(executor.get_position().x, 0);
    EXPECT_EQ(executor.get_position().y, 8);
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("LMM");
    EXPECT_EQ(executor.get_position().x, -2);
    EXPECT_EQ(executor.get_position().y, 8);
    EXPECT_EQ(executor.get_directions(), 'W');
    executor.execute("R");
    EXPECT_EQ(executor.get_position().x, -2);
    EXPECT_EQ(executor.get_position().y, 8);
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("RMMMM");
    EXPECT_EQ(executor.get_position().x, 2);
    EXPECT_EQ(executor.get_position().y, 8);
    EXPECT_EQ(executor.get_directions(), 'E');
    executor.execute("RMMM");
    EXPECT_EQ(executor.get_position().x, 2);
    EXPECT_EQ(executor.get_position().y, 5);
    EXPECT_EQ(executor.get_directions(), 'S');
}