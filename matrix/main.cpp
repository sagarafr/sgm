//
// Created by gappa_a on 9/12/16.
//

#include	<iostream>
#include	"test.hpp"
#include    "matrix.hpp"

int		main(void)
{
    Matrix<int> m(5, 10);
    std::cout << "hello" << std::endl;
    testing();
    std::cout << m.line() << ' ' << m.column() << std::endl;
    for (uint16_t cpt_line(0) ; cpt_line < m.line() ; ++cpt_line)
    {
        for (uint16_t cpt_column(0) ; cpt_column < m.column() ; ++cpt_column)
            std::cout << m(cpt_line, cpt_column) << ' ';
        std::cout << std::endl;
    }
  return (0);
}
