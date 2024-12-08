#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"
using namespace car;
TEST(ExecutorTest, should_return_x_plus_2_given_status_is_fast_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'E'));

    // when
    executor->execute("FM");

    // then
    const Pose target{2, 0, 'E'};
    ASSERT_EQ(executor->getPose(), target);
}
