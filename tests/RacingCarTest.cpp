#include <gtest/gtest.h>

#include "Executor.hpp"
#include "Point.hpp"
#include "RacingCar.hpp"
using namespace adas;

TEST(RacingCarTest, should_return_N_and_y_plus_1_when_command_is_L_and_facing_is_E_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<RacingCar>({0, 0}, 'E'));

    // when
    executor->execute("L");

    // then
    const Pose target{0, 1, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(RacingCarTest, should_return_S_and_y_minus_1_when_command_is_R_and_facing_is_E_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<RacingCar>({0, 0}, 'E'));

    // when
    executor->execute("R");

    // then
    const Pose target{0, -1, 'S'};
    ASSERT_EQ(executor->getPose(), target);
}

TEST(RacingCarTest, should_return_y_plus_2_when_command_is_M_and_facing_is_N_and)
{
    // given
    std::unique_ptr<Executor> executor(Executor::NewExecutor<RacingCar>({0, 0}, 'N'));

    // when
    executor->execute("M");

    // then
    const Pose target{0, 2, 'N'};
    ASSERT_EQ(executor->getPose(), target);
}
