#include "Fixed.hpp"

Fixed(const int n)
{
    std::cout << "int constructor called." << std::endl;
}

Fixed(const float f)
{
    std::cout << ":Float constructur called" << std::endl;
    _value = roundf(f*(1<<_fbits));
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _fbits));
}

int Fixed::toInt(void) const
{
    return (_value >> _fbits;); 
}