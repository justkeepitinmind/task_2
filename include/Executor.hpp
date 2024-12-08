#pragma once

#include <iostream>
#include <vector>

#include "Point.hpp"
#include "PoseHandler.hpp"
namespace car
{
class Executor
{
public:
    // use default contruction and deconstruction function
    Executor(void) = default;
    virtual ~Executor(void) = default;

    Executor(const Executor&) = delete;
    Executor operator=(const Executor&) = delete;

    // 是否在加速
    static Executor* NewExecutor(const PoseHandler& poseHanler = {});

    virtual Point getPosition() const noexcept = 0;

    virtual char getDirection() const noexcept = 0;

    virtual void execute(const std::string& s) noexcept = 0;
};
}  // namespace car