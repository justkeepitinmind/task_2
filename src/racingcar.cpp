#include "RacingCar.hpp"

namespace car
{
class RacingCarTurnLeftCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.turnLeft();
        poseHandler.move();
    }
};

class RacingCarTurnRightCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.turnRight();
        poseHandler.move();
    }
};

class RacingCarMoveCommand final
{
public:
    void operator()(PoseHandler& poseHandler) const noexcept
    {
        poseHandler.move();
        poseHandler.move();
    }
};

void RacingCar::execute(const std::string& s) noexcept
{
    std::unordered_map<char, Command> cmderMap{
        {'M', RacingCarMoveCommand()},
        {'L', RacingCarTurnLeftCommand()},
        {'R', RacingCarTurnRightCommand()},
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
}  // namespace car