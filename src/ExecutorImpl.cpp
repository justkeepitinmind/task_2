#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "Command.hpp"
namespace car
{

Point ExecutorImpl::getPosition() const noexcept
{
    return poseHandler.getPosition();
}

char ExecutorImpl::getDirection() const noexcept
{
    return poseHandler.getDirection();
}

void ExecutorImpl::execute(const std::string& s) noexcept
{
    std::unordered_map<char, std::unique_ptr<ICommand>> cmderMap;
    cmderMap['M'] = std::make_unique<MoveCommand>();
    cmderMap['L'] = std::make_unique<TurnLeftCommand>();
    cmderMap['R'] = std::make_unique<TurnRightCommand>();
    cmderMap['F'] = std::make_unique<ChangeSpeedCommand>();

    for (const auto ch : s) {
        std::unique_ptr<ICommand> cmd;
        if (cmderMap.find(ch) != cmderMap.end()) {
            cmderMap[ch]->DoOperator(poseHandler);
        } else {
            std::cerr << "unkown instruction " << ch << ".\n";
        }
    }
}

}  // namespace car