#pragma once
#include <memory>

#include "BaseExecutor.hpp"

namespace adas
{
class RacingCar final : public BaseExecutor
{
public:
    explicit RacingCar(const Point& p, char d) noexcept : BaseExecutor(p, d) {};

    RacingCar() noexcept : BaseExecutor() {};

    void execute(const std::string& s) noexcept override;
};
}  // namespace adas