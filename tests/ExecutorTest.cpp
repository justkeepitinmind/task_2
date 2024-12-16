#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"

using namespace adas;

TEST(ExecutorTest, should_return_init_pose_when_without_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({5, 2}, 'E'));

    // when

    // then
    const Pose target{5, 2, 'E'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor());

    // when

    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'E'));

    // when
    executor->execute("M");

    // then
    const Pose target{1, 0, 'E'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'W'));

    // when
    executor->execute("M");

    // then
    const Pose target{-1, 0, 'W'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'N'));

    // when
    executor->execute("M");

    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'S'));

    // when
    executor->execute("M");

    // then
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(executor->getPose(), target);
}
