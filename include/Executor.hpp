#pragma once

#include <iostream>
#include <vector>

#include "Point.hpp"
namespace car
{
class Executor
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

    void move()
    {
        p += DIRECTION[heading];
    }

    void turn_right()
    {
        heading = nxt(heading);
    }

    void turn_left()
    {
        heading = pre(heading);
    }

public:
    Executor() : p(), heading(0) {};
    Executor(const Point& p, char d);
    Point get_position() const
    {
        return p;
    };

    char get_directions() const
    {
        return DIRECTION_NAME[heading];
    }

    void execute(const std::string& s);
};
}  // namespace car