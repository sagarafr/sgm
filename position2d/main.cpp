#include <iostream>
#include "position2d.hpp"

int main(void)
{
    sgm::position::Position2D<uint64_t, uint64_t> position;
    std::cout << position.getY() << " " << position.getX() << std::endl;
    return (0);
}