#pragma once
#include <memory>

#include "BaseExecutor.hpp"

namespace car
{
class Bus final : public BaseExecutor
{
public:
    explicit Bus(const Point& p, char d) noexcept : BaseExecutor(p, d) {};

    Bus() noexcept : BaseExecutor() {};

    void execute(const std::string& s) noexcept override;
};
}  // namespace car