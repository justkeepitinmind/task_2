#pragma once
#include <memory>

#include "Executor.hpp"

namespace car
{
class ExecutorImpl final : public Executor
{
public:
    ExecutorImpl(const Point& p, char d) : Executor(p, d) {};
    ExecutorImpl() : Executor() {};

    void execute(const std::string& s);
};
}  // namespace car