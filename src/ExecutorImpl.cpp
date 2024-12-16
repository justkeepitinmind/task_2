
#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "Command.hpp"
namespace car
{

Executor* Executor::NewExecutor(const Point& position, const char direction) noexcept
{
    return new ExecutorImpl(position, direction);
};

Point ExecutorImpl::getPosition() const noexcept
{
    return poseHandler.getPosition();
}

char ExecutorImpl::getDirection() const noexcept
{
    return poseHandler.getDirection();
}

Pose ExecutorImpl::getPose() const noexcept
{
    return poseHandler.getPose();
};

void ExecutorImpl::execute(const std::string& s) noexcept
{
    std::unordered_map<char, Command> cmderMap{{'M', MoveCommand()},
                                               {'L', TurnLeftCommand()},
                                               {'R', TurnRightCommand()},
                                               {'F', ChangeSpeedCommand()},
                                               {'B', ReverseCommand()}};

    for (const auto cmd : s) {
        auto it = cmderMap.find(cmd);
        if (it != cmderMap.end()) {
            it->second(poseHandler);
        } else {
            std::cerr << "unkown instruction " << cmd << ".\n";
        }
    }
}

}  // namespace car