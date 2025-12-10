#include "Fixed.hpp"

int main(void)
{
    // int x = 0b00000000000000000000000000001111;
    // int y = 0x000F;
    // int z = 15;
    // printf("%d\n", x);
    // printf("%d\n", y);
    // printf("%d\n", z);
    // return (0);
    Fixed a;
    Fixed const b( 10 );
    // std::cout << b.getRawBits() << std::endl;
    Fixed const c( 42.42f );
    // std::cout << c.getRawBits() << std::endl;
    Fixed const d( b );
    a = Fixed( 1234.4321f );
    // std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
