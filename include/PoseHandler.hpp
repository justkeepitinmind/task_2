#pragma once

#include <iostream>
#include <vector>

#include "Point.hpp"
namespace car
{
class PoseHandler
{
private:
    // 0 <==> N <==> {0,1}
    // 1 <==> E <==> {1,0}
    // 2 <==> S <==> {0,-1}
    // 3 <==> E <==> {-1,0}
    // turn right <==> idx++ (mod 4)
    // turn left  <==> idx-- (mod 4)
    Point p;
    size_t heading;
    bool fast;

public:
    PoseHandler() : p(), heading(0), fast(0) {};
    explicit PoseHandler(const Point& p, char d) noexcept;

    void changeSpeed() noexcept;

    void move() noexcept;

    void turnRight() noexcept;

    void turnLeft() noexcept;

    // 是否在加速
    bool isFast() const noexcept;

    Point getPosition() const noexcept;

    char getDirection() const noexcept;

    Pose getPose() const noexcept;
};
}  // namespace car