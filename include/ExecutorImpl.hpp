#pragma once
#include <memory>

#include "Executor.hpp"

namespace car
{
class ExecutorImpl final : public Executor
{
private:
    PoseHandler poseHandler;

public:
    explicit ExecutorImpl(const Point& p, char d) noexcept : poseHandler(p, d) {};

    ExecutorImpl() noexcept : poseHandler() {};

    Point getPosition() const noexcept override;

    char getDirection() const noexcept override;

    Pose getPose() const noexcept override;

    void execute(const std::string& s) noexcept override;
};
}  // namespace car