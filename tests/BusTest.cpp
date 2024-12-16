#include <gtest/gtest.h>

#include "Bus.hpp"
#include "Executor.hpp"
#include "Point.hpp"
using namespace adas;

TEST(BusTest, should_return_N_and_x_plus_1_when_command_is_L_and_facing_is_E_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<Bus>({0, 0}, 'E'));

    // when
    executor->execute("L");

    // then
    const Pose target{1, 0, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(BusTest, should_return_S_and_x_plus_1_when_command_is_R_and_facing_is_E_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<Bus>({0, 0}, 'E'));

    // when
    executor->execute("R");

    // then
    const Pose target{1, 0, 'S'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(BusTest, should_return_y_plus_1_when_command_is_M_and_facing_is_N_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<Bus>({0, 0}, 'N'));

    // when
    executor->execute("M");

    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}
