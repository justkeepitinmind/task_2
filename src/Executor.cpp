#include "Executor.hpp"

#include <vector>
namespace car
{
// heading表示朝向，对应四个方向（N、S、E、W）(均为char类型)
const std::vector<Point> Executor::DIRECTION = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const std::vector<char> Executor::DIRECTION_NAME = {'N', 'E', 'S', 'W'};

Executor::Executor(const Point& p, char d) : p(p), speedUp(0)
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
            if (isSpeedUp())
                move();
            break;
        case 'L':
        case 'l':
            turnLeft();
            break;
        case 'R':
        case 'r':
            turnRight();
            break;
        case 'F':
        case 'f':
            changeSpeed();
            break;
        default:
            std::cerr << "unkown instruction " << ch << ".\n";
        }
    }
}
}  // namespace car