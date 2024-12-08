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
    const static std::vector<Point> DIRECTION;
    const static std::vector<char> DIRECTION_NAME;

    inline static int nxt(int x)
    {
        return x == 3 ? 0 : x + 1;
    }
    inline static int pre(int x)
    {
        return x == 0 ? 3 : x - 1;
    }

    Point p;
    size_t heading;
    bool fast;

public:
    PoseHandler() : p(), heading(0), fast(0) {};
    PoseHandler(const Point& p, char d);

    void changeSpeed()
    {
        fast = !fast;
    }

    void move()
    {
        p += DIRECTION[heading];
    }

    void turnRight()
    {
        heading = nxt(heading);
    }

    void turnLeft()
    {
        heading = pre(heading);
    }

    // 是否在加速
    bool isFast() const
    {
        return fast;
    }

    Point getPosition() const
    {
        return p;
    };

    char getDirection() const
    {
        return DIRECTION_NAME[heading];
    }
};
}  // namespace car