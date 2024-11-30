#include <memory>

#include "Executor.hpp"

namespace car
{
class ExecutorImpl final : public Executor
{
public:
    class ICommand
    {
    public:
        virtual ~ICommand() = default;
        virtual void DoOperator(ExecutorImpl& executor) const noexcept = 0;
    };

    class TurnLeftCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            executor.turnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            executor.turnRight();
        }
    };

    class MoveCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            executor.move();
            if (executor.isSpeedUp())
                executor.move();
        }
    };

    class ChangeSpeedCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            executor.changeSpeed();
        }
    };

    void execute(const std::string& s);
};
}  // namespace car