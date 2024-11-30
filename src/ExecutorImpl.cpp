#include "ExecutorImpl.hpp"

#include <memory>
namespace car
{
void ExecutorImpl::execute(const std::string& s)
{
    for (const auto ch : s) {
        if (ch == 'm' || ch == 'M') {
            std::unique_ptr<ICommand> cmd(new MoveCommand());
            cmd->DoOperator(*this);
            cmd.release();
        } else if (ch == 'L' || ch == 'l') {
            std::unique_ptr<ICommand> cmd(new TurnLeftCommand());
            cmd->DoOperator(*this);
            cmd.release();
        } else if (ch == 'R' || ch == 'r') {
            std::unique_ptr<ICommand> cmd(new TurnRightCommand());
            cmd->DoOperator(*this);
            cmd.release();
        } else if (ch == 'F' || ch == 'f') {
            std::unique_ptr<ICommand> cmd(new ChangeSpeedCommand());
            cmd->DoOperator(*this);
            cmd.release();
        } else {
            std::cerr << "unkown instruction " << ch << ".\n";
        }
    }
}

}  // namespace car