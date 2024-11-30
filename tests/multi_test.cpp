#include <gtest/gtest.h>

#include "Executor.hpp"
#include "Point.hpp"
using namespace car;
TEST(Executor, test_case)
{
    Executor executor(Point{0, 4}, 'N');
    EXPECT_EQ(executor.get_position(), Point(0, 4));
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("MMMM");
    EXPECT_EQ(executor.get_position(), Point(0, 8));
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("LMM");
    EXPECT_EQ(executor.get_position(), Point(-2, 8));
    EXPECT_EQ(executor.get_directions(), 'W');
    executor.execute("R");
    EXPECT_EQ(executor.get_directions(), 'N');
    executor.execute("RMMMM");
    EXPECT_EQ(executor.get_position(), Point(2, 8));
    EXPECT_EQ(executor.get_directions(), 'E');
    executor.execute("RMMM");
    EXPECT_EQ(executor.get_position(), Point(2, 5));
    EXPECT_EQ(executor.get_directions(), 'S');
}