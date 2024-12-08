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
    ExecutorImpl(const Point& p, char d) : poseHandler(p, d) {};
    ExecutorImpl() : poseHandler() {};

    Point getPosition() const noexcept override;

    char getDirection() const noexcept override;

    void execute(const std::string& s) noexcept override;
};
}  // namespace car