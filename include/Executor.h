#pragma once

#include <iostream>
#include <vector>

#include "point.h"
class Executor
{
private:
    // 0 <==> N <==> {0,1}
    // 1 <==> E <==> {1,0}
    // 2 <==> S <==> {0,-1}
    // 3 <==> E <==> {-1,0}
    // turn right <==> idx++ (mod 4)
    // turn left  <==> idx-- (mod 4)
    const static std::vector<point> direction;
    const static std::vector<char> direction_name;
    inline static int nxt(int x)
    {
        return x == 3 ? 0 : x + 1;
    }
    inline static int pre(int x)
    {
        return x == 0 ? 3 : x - 1;
    }

    point p;
    size_t heading;

    void move()
    {
        p += direction[heading];
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
    Executor(const point& p, char d);
    point get_position() const
    {
        return p;
    };

    char get_directions() const
    {
        return direction_name[heading];
    }

    void execute(const std::string& s);
};