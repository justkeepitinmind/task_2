#include <memory>

#include "Executor.hpp"

namespace car
{
class ExecutorImpl final : public Executor
{
public:
    ExecutorImpl(const Point& p, char d) : Executor(p, d) {};
    ExecutorImpl() : Executor() {};

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
            if (executor.isSpeedUp())
                executor.move();
            executor.turnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            if (executor.isSpeedUp())
                executor.move();
            executor.turnRight();
        }
    };

    class MoveCommand final : public ICommand
    {
        void DoOperator(ExecutorImpl& executor) const noexcept override
        {
            if (executor.isSpeedUp())
                executor.move();
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