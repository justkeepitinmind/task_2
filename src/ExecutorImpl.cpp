
#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "Command.hpp"
namespace adas
{

Executor* Executor::NewExecutor(const Point& position, const char direction) noexcept
{
    return new ExecutorImpl(position, direction);
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

}  // namespace adas