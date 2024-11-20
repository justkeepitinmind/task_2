#include "Executor.h"

#include <vector>
// heading表示朝向，对应四个方向（N、S、E、W）(均为char类型)
const std::vector<point> Executor::direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::vector<char> Executor::direction_name = {'N', 'E', 'S', 'W'};

Executor::Executor(const point& p, char d) : p(p)
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

void Executor::execute(const std::string& s)
{
    for (const auto ch : s) {
        switch (ch) {
        case 'M':
        case 'm':
            move();
            break;
        case 'L':
        case 'l':
            turn_left();
            break;
        case 'R':
        case 'r':
            turn_right();
            break;
        default:
            std::cerr << "unkown instruction " << ch << ".\n";
        }
    }
}