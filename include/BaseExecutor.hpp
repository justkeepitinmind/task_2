#pragma once

#include <functional>

#include "Executor.hpp"

namespace adas
{
using Command = std::function<void(PoseHandler& poseHandler)>;

class BaseExecutor : public Executor
{
protected:
    PoseHandler poseHandler;

public:
    explicit BaseExecutor(const Point& p, char d) noexcept : poseHandler(p, d) {};

    BaseExecutor() noexcept : poseHandler() {};

    Point getPosition() const noexcept override;

    char getDirection() const noexcept override;

    Pose getPose() const noexcept override;
};
}  // namespace adas