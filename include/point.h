#pragma once

struct point {
    int x, y;
    bool operator==(const point& o) const
    {
        return x == o.x && y == o.y;
    }
    void operator+=(const point& o)
    {
        x += o.x, y += o.y;
    }
    void operator-=(const point& o)
    {
        x -= o.x, y -= o.y;
    }
    point operator+(const point& o) const
    {
        return {x + o.x, y + o.y};
    }
    point operator-(const point& o) const
    {
        return {x - o.x, y - o.y};
    }
};