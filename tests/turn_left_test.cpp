// #include <gtest/gtest.h>

// #include "Executor.hpp"
// #include "Point.hpp"
// using namespace car;
// TEST(Executor, Executor_Turn_Left_Test)
// {
//     Executor executor({2, 5}, 'S');
//     EXPECT_EQ(executor.getDirection(), 'S');

//     executor.execute("L");
//     EXPECT_EQ(executor.getDirection(), 'E');

//     executor.execute("L");
//     EXPECT_EQ(executor.getDirection(), 'N');

//     executor.execute("L");
//     EXPECT_EQ(executor.getDirection(), 'W');

//     executor.execute("L");
//     EXPECT_EQ(executor.getDirection(), 'S');
// }