#include <gtest/gtest.h>

#include "Executor.hpp"
#include "ExecutorImpl.hpp"
#include "Point.hpp"

using namespace adas;

// R
TEST(ExecutorTest, should_return_facing_S_given_command_is_R_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'E'));

    // when
    executor->execute("R");

    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_R_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'S'));

    // when
    executor->execute("R");

    // then
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_N_given_command_is_R_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'W'));

    // when
    executor->execute("R");

    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_R_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'N'));

    // when
    executor->execute("R");

    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(executor->getPose(), target);
}

// L

TEST(ExecutorTest, should_return_facing_S_given_command_is_L_and_facing_is_W)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'W'));

    // when
    executor->execute("L");

    // then
    const Pose target{0, 0, 'S'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_W_given_command_is_L_and_facing_is_N)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'N'));

    // when
    executor->execute("L");

    // then
    const Pose target{0, 0, 'W'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_N_given_command_is_L_and_facing_is_E)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'E'));

    // when
    executor->execute("L");

    // then
    const Pose target{0, 0, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(ExecutorTest, should_return_facing_E_given_command_is_L_and_facing_is_S)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0}, 'S'));

    // when
    executor->execute("L");

    // then
    const Pose target{0, 0, 'E'};
    ASSERT_EQ(executor->getPose(), target);
}
