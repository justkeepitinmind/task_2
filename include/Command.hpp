#pragma once
#include "ExecutorImpl.hpp"

namespace car
{
class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual void DoOperator(PoseHandler& poseHandler) const noexcept = 0;
};

class TurnLeftCommand final : public ICommand
{
    void DoOperator(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.turnLeft();
    }
};

class TurnRightCommand final : public ICommand
{
    void DoOperator(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.turnRight();
    }
};

class MoveCommand final : public ICommand
{
    void DoOperator(PoseHandler& poseHandler) const noexcept override
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.move();
    }
};

class ChangeSpeedCommand final : public ICommand
{
    void DoOperator(PoseHandler& poseHandler) const noexcept override
    {
        poseHandler.changeSpeed();
    }
};
}