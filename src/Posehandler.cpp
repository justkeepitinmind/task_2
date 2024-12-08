#include "PoseHandler.hpp"

namespace car
{
// heading表示朝向，对应四个方向（N、S、E、W）(均为char类型)
const std::vector<Point> PoseHandler::DIRECTION = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::vector<char> PoseHandler::DIRECTION_NAME = {'N', 'E', 'S', 'W'};

void PoseHandler::changeSpeed() noexcept
{
    fast = !fast;
}

void PoseHandler::move() noexcept
{
    p += DIRECTION[heading];
}

void PoseHandler::turnRight() noexcept
{
    heading = nxt(heading);
}

void PoseHandler::turnLeft() noexcept
{
    heading = pre(heading);
}

// 是否在加速
bool PoseHandler::isFast() const noexcept
{
    return fast;
}

Point PoseHandler::getPosition() const noexcept
{
    return p;
};

char PoseHandler::getDirection() const noexcept
{
    return DIRECTION_NAME[heading];
}

Pose PoseHandler::getPose() const noexcept
{
    return Pose{getPosition(), getDirection()};
};

PoseHandler::PoseHandler(const Point& p, char d) noexcept : p(p), fast(0)
{
    switch (d) {
    case 'N':
        heading = 0;
        break;
    case 'E':
        heading = 1;
        break;
    case 'S':
        heading = 2;
        break;
    case 'W':
        heading = 3;
        break;
    default:
        heading = 0;
        break;
    }
};

}  // namespace car