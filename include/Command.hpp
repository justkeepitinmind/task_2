#pragma once
#include "ExecutorImpl.hpp"

namespace car
{
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperator(ExecutorImpl& executor) const noexcept = 0;
};

class TurnLeftCommand final : public ICommand
{
    void DoOperator(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.move();
        executor.turnLeft();
    }
};

class TurnRightCommand final : public ICommand
{
    void DoOperator(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.move();
        executor.turnRight();
    }
};

class MoveCommand final : public ICommand
{
    void DoOperator(ExecutorImpl& executor) const noexcept override
    {
        if (executor.isFast())
            executor.move();
        executor.move();
    }
};

class ChangeSpeedCommand final : public ICommand
{
    void DoOperator(ExecutorImpl& executor) const noexcept override
    {
        executor.changeSpeed();
    }
};
}