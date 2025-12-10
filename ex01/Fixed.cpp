#include "Fixed.hpp"
#include <limits>

void print_msg(std::string msg)
{
    std::cout << msg <<std::endl;
}

Fixed::Fixed(void) : value_(0)
{
    print_msg("Fixed::Default constructor called");
}

Fixed::Fixed(const Fixed &other) : value_(other.value_)
{
    print_msg("Fixed::Copy constructor called");
}

Fixed::~Fixed(void)
{
    print_msg("Fixed::destructor called");
}

Fixed &Fixed::operator=(Fixed const &other)
{
    print_msg("Fixed::Copy assignment operator called");
    // value_=other.getRawBits();
    value_=other.value_;
    return (*this);
}

int     Fixed::getRawBits(void) const
{
    return (value_);
}

void    Fixed::setRawBits(int const raw)
{
    print_msg("Fixed::setRawBits() called");    
    value_ = raw;
}

//ex01 NEW
/*
    if f == 3.1415;
    then value_ = 3.1415 * 2^8
*/
/*
    +8,388,608
    -8,388,608
*/

Fixed::Fixed(const int value) : value_(value<<fbits_)
{
    if (value>0x8000 - 0x0001)
        std::cerr << "recept int value overflows. Fixed can repareset -8,388,608~8,388,608" << std::endl;
   else if (value < -(0x8000 - 0x0001))
        std::cerr << "recept int value overflows. Fixed can repareset -8,388,608~8,388,608" << std::endl;
    print_msg("Fixed::int value constructor called");
}

//float -> int -> shift
Fixed::Fixed(const float value)
{
    print_msg("Fixed::float value constructor called");
    if (value>static_cast<float>(0x8000 - 0x0001))
        std::cerr << "recept float value overflows. Fixed can repareset -8,388,608~8,388,608" << std::endl;
    else if (value < -static_cast<float>(0x8000 - 0x0001))
        std::cerr << "recept int value overflows. Fixed can repareset -8,388,608~8,388,608" << std::endl;
    //shift float
    float shift = value * (1<<fbits_);
    float round = roundf(shift);
    int    cast = static_cast<int>(round);
    std::cout << "Fixed::assignment constructor: float casted to " << cast << std::endl;
    value_ = cast;
    //cast to int
    // value_ = (static_cast<int>(roundf(value*(1<<fbits_))));
}

/*
    if value_ == 0010 1010 0000 0000 ...
    then ret = (float)(value_ / 2^8)
*/
float Fixed::toFloat(void) const
{
    // return ((float)value_ / (1 << fbits_));
    int divisor = (1<<fbits_);
    /*
        fbits_=8;
        divisor = 0000 0000 0000 0001 << 8;
        divisor = 0000 0001 0000 0000;
    */
    float inverse_divisor = 1.0f / static_cast<float>(divisor);
    /*
        inverse_divisor = 1.0000 / 256.0000
        inverse_divisor = 0.00390625;
    */
    float result = static_cast<float>(value_) * inverse_divisor;
    /*
        value_= 0d10 = 0b1010; 
        result = <float>(value_) * <flaot>(inverse_divisor);
        result = 10.0000 * 0.0390625;
        result = 0.390625;
        <int>culculation
        result = 0b1010 / (1<<fbits_);
        result ?=0.012265625;
    */
    return (result);
}

// 0x00 0x00 0x00 0x00

int Fixed::toInt(void) const
{
    return (value_ >> fbits_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    // int value_local = fixed.getRawBits();
    //0x00 0x00 0x00 . 0x00
    /*
        LSB: 8bit : 256 : 0b0000 0000 : 0x0011
    */
    // int fractional_mask = 0xFF;
    // int fractional_part = value_local & fractional_mask;
    // int integer_part = fixed.toInt();
    // std::cout << "value_local: " << value_local << std::endl;
    // std::cout << "fractional mask: " << fractional_mask << std::endl;
    // std::cout << "fractional_part: " << fractional_part << std::endl;
    // std::cout << "fractional_part: " << fractional_part << std::endl;
    // std::string buf;
    // buf = std::to_string(integer_part) + "." + std::to_string(fractional_part);
    // os << buf;
    os << fixed.toFloat();
    return (os);
}
