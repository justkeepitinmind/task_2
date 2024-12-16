#include "Bus.hpp"

namespace adas
{
class BusTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.move();
        poseHandler.turnLeft();
    }
};

class BusTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.move();
        poseHandler.turnRight();
    }
};

class BusMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.move();
    }
};

void Bus::execute(const std::string& s) noexcept
{
    std::unordered_map<char, Command> cmderMap{
        {'M', BusMoveCommand()},
        {'L', BusTurnLeftCommand()},
        {'R', BusTurnRightCommand()},
    };

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