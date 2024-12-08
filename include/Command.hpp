#pragma once
#include <functional>

#include "ExecutorImpl.hpp"
namespace car
{
using Command = std::function<void(PoseHandler& poseHandler)>;

class TurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.turnLeft();
    }
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.turnRight();
    }
};

class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.isFast())
            poseHandler.move();
        poseHandler.move();
    }
};

class ChangeSpeedCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.changeSpeed();
    }
};

class ReverseCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.reverse();
    }
};
}  // namespace car