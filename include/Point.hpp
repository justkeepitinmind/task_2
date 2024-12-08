#pragma once
#include <iostream>
namespace car
{
struct Point {
    int x, y;
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {};

    bool operator==(const Point& o) const noexcept
    {
        return x == o.x && y == o.y;
    }
    void operator+=(const Point& o) noexcept
    {
        x += o.x, y += o.y;
    }
    void operator-=(const Point& o) noexcept
    {
        x -= o.x, y -= o.y;
    }
    Point operator+(const Point& o) const noexcept
    {
        return {x + o.x, y + o.y};
    }
    Point operator-(const Point& o) const noexcept
    {
        return {x - o.x, y - o.y};
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) noexcept
    {
        return os << p.x << " " << p.y;
    }
};
}  // namespace car