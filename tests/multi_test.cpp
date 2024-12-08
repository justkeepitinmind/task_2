// #include <gtest/gtest.h>

// #include "Executor.hpp"
// #include "Point.hpp"
// using namespace car;
// TEST(Executor, test_case)
// {
//     Executor executor(Point{0, 4}, 'N');
//     EXPECT_EQ(executor.getPosition(), Point(0, 4));
//     EXPECT_EQ(executor.getDirection(), 'N');
//     executor.execute("MMMM");
//     EXPECT_EQ(executor.getPosition(), Point(0, 8));
//     EXPECT_EQ(executor.getDirection(), 'N');
//     executor.execute("LMM");
//     EXPECT_EQ(executor.getPosition(), Point(-2, 8));
//     EXPECT_EQ(executor.getDirection(), 'W');
//     executor.execute("R");
//     EXPECT_EQ(executor.getDirection(), 'N');
//     executor.execute("RMMMM");
//     EXPECT_EQ(executor.getPosition(), Point(2, 8));
//     EXPECT_EQ(executor.getDirection(), 'E');
//     executor.execute("RMMM");
//     EXPECT_EQ(executor.getPosition(), Point(2, 5));
//     EXPECT_EQ(executor.getDirection(), 'S');
// }