#include "Fixed.hpp"

void print_msg(std::string msg)
{
    std::cout << msg <<std::endl;
}

Fixed::Fixed(void) : value_(0)
{
    std::cout << "Default constructor called" <<std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "destructor called" <<std::endl;
}

Fixed &Fixed::operator=(Fixed const &other)
{
    std::cout <<"Copy assignment operator called" << std::endl;
}
