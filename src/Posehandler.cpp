#include "PoseHandler.hpp"

namespace adas
{
// heading表示朝向，对应四个方向（N、S、E、W）(均为char类型)
const std::vector<Point> __DIRECTION = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::vector<char> __DIRECTION_NAME = {'N', 'E', 'S', 'W'};

void PoseHandler::changeSpeed() noexcept
{
    fast = !fast;
}

void PoseHandler::go_forward() noexcept
{
    p += __DIRECTION[heading];
}

void PoseHandler::go_back() noexcept
{
    p -= __DIRECTION[heading];
}

void PoseHandler::move() noexcept
{
    if (forward)
        go_forward();
    else
        go_back();
}

void PoseHandler::reverse() noexcept
{
    forward = !forward;
};

void PoseHandler::turnRight() noexcept
{
    heading = heading == 3 ? 0 : heading + 1;
}

void PoseHandler::turnLeft() noexcept
{
    heading = heading == 0 ? 3 : heading - 1;
}

// 是否在加速
bool PoseHandler::isFast() const noexcept
{
    return fast;
}

bool PoseHandler::isForward() const noexcept
{
    return forward;
}

Point PoseHandler::getPosition() const noexcept
{
    return p;
};

char PoseHandler::getDirection() const noexcept
{
    return __DIRECTION_NAME[heading];
}

Pose PoseHandler::getPose() const noexcept
{
    return Pose{getPosition(), getDirection()};
};

PoseHandler::PoseHandler(const Point& p, char d) noexcept : p(p), fast(0), forward(1)
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

}  // namespace adas