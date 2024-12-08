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

    Point operator*(const int a) const noexcept
    {
        return {a * x, a * y};
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p) noexcept
    {
        return os << p.x << " " << p.y;
    }
};

struct Pose {
    Point p;
    char heading;
    Pose() noexcept : p({0, 0}), heading('N')
    {
    }

    explicit Pose(const Point& p, const char heading) noexcept : p(p), heading(heading)
    {
    }

    explicit Pose(const int x, const int y, const char heading) noexcept : p(x, y), heading(heading)
    {
    }

    bool operator==(const Pose& o) const noexcept
    {
        return p == o.p && heading == o.heading;
    }

    friend std::ostream& operator<<(std::ostream& os, Pose& pose) noexcept
    {
        return os << "position: " << pose.p << " heading :" << pose.heading;
    }
};
}  // namespace car