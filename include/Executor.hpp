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

    template <class T>
    static Executor* NewExecutor(const Point& position = {0, 0}, const char direction = 'N') noexcept
    {
        return new T(position, direction);
    };

    static Executor* NewExecutor(const Point& position = {0, 0}, const char direction = 'N') noexcept;

    virtual Point getPosition() const noexcept = 0;

    virtual char getDirection() const noexcept = 0;

    virtual Pose getPose() const noexcept = 0;

    virtual void execute(const std::string& s) noexcept = 0;
};
}  // namespace car