#pragma once
namespace car
{
struct Point {
    int x, y;
    Point() : x(0), y(0) {};
    Point(int x, int y) : x(x), y(y) {};

    bool operator==(const Point& o) const
    {
        return x == o.x && y == o.y;
    }
    void operator+=(const Point& o)
    {
        x += o.x, y += o.y;
    }
    void operator-=(const Point& o)
    {
        x -= o.x, y -= o.y;
    }
    Point operator+(const Point& o) const
    {
        return {x + o.x, y + o.y};
    }
    Point operator-(const Point& o) const
    {
        return {x - o.x, y - o.y};
    }
};
}  // namespace car