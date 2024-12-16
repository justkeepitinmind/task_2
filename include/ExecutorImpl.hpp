#pragma once

#include "BaseExecutor.hpp"

namespace car
{
class ExecutorImpl final : public BaseExecutor
{
public:
    explicit ExecutorImpl(const Point& p, char d) noexcept : BaseExecutor(p, d) {};

    ExecutorImpl() noexcept : BaseExecutor() {};

    void execute(const std::string& s) noexcept override;
};
}  // namespace car