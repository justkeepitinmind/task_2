
#include "BaseExecutor.hpp"

#include <memory>
#include <unordered_map>

#include "Command.hpp"
#include "ExecutorImpl.hpp"

namespace adas
{

Point BaseExecutor::getPosition() const noexcept
{
    return poseHandler.getPosition();
}

char BaseExecutor::getDirection() const noexcept
{
    return poseHandler.getDirection();
}

Pose BaseExecutor::getPose() const noexcept
{
    return poseHandler.getPose();
};

}  // namespace adas