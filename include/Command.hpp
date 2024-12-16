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
        if (poseHandler.isFast()) {
            poseHandler.move();
        }
        if (poseHandler.isForward()) {
            poseHandler.turnLeft();
        } else {
            poseHandler.turnRight();
        }
    }
};

class TurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.isFast()) {
            poseHandler.move();
        }
        if (poseHandler.isForward()) {
            poseHandler.turnRight();
        } else {
            poseHandler.turnLeft();
        }
    }
};

class MoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        if (poseHandler.isFast()) {
            poseHandler.move();
        }
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