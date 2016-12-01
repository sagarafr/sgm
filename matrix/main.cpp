#include <iostream>
#include "matrix.hpp"

int		main(void)
{
    sgm::matrix::Matrix<int> m(5, 10);
    m(4, 9) = 10;
    std::cout << "hello" << std::endl;
    std::cout << m.line() << ' ' << m.column() << std::endl;
    return (0);
}
