#include "Fixed.hpp"

// #define DoubleToFixed(x) (x*(double)(1<<scale))
// #define FixedToDouble(x) ((double)x / (double)(1<<scale))
// #define IntToFixed(x) (x << scale)
// #define FixedToInt(x) (x >> scale)
// #define MUL(x,y) (((x)*(y)) >> scale)
// #define DIV(x,y) ((x) << scale)
// https://stackoverflow.com/questions/67517939/how-to-connect-the-theory-of-fixed-point-numbers-and-its-practical-implementatio

//when multiplication and devision, if there is possibility of overflow,
//then cast to bigger type and culculate it.

Fixed::Fixed() : value_(0)
{
    std::cout << "default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called." << std::endl;
    value_=src.getRawBits();
}

Fixed::Fixed(const int n) :value_(n)
{
    std::cout << "int constructor called." << std::endl;
}

Fixed::Fixed(const float f): value_((int)roundf(f*(1<<fbits_)))
{
    std::cout << "Float constructur called" << std::endl;
    // value_ = (int)roundf(f*(1<<fbits_));//value*2^8
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return (value_);
}

void Fixed::setRawBits(int const value)
{
    value_=value;
}

//initially cast to float
float Fixed::toFloat(void) const
{
    return ((float)value_ / (1 << fbits_));

    //cast and devide

    //devide and cast

}

// 0x00 0x00 0x00 0x00

int Fixed::toInt(void) const
{
    return (value_ >> fbits_); //value/2^8
}

//unique_ptr<> cannnot be assigned.
//if you want to move the ownership, use move(unique_ptr);
//the previous ptr gets nullptr.

//shared_ptr<> can share the ownership.
//shPtr.use_count() gets the count of the current oweners.

//weak_ptr<> won't have the ownership of shared_ptr, but it can refer to it.
//the count of shared_ptr won't increase.

/*
scope limitation
{
}
has the effect to limit the life-time of pointer.
*/

Fixed &Fixed::operator=(Fixed const &other)
{
    std::cout <<"Copy assignment operator called" << std::endl;
    value_=other.getRawBits();
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    int value_local = fixed.getRawBits();
    //0x00 0x00 0x00 . 0x00
    int fractional_mask = 0b0000000000000000000000001111;//32bit:0x0008
    int fractional_part = value_local & fractional_mask;
    int integer_part = fixed.toInt();
    std::string buf;
    buf = std::to_string(integer_part) + "." + std::to_string(fractional_part);
    os << buf;
    return (os);
}

// std::string &operator<<(std::ostream &os, Fixed &fixed)
// {
//     int value_local = fixed.getRawBits();
//     //0x00 0x00 0x00 . 0x00
//     int fractional_mask = 0b0000000000000000000000001111;//32bit:0x0008
//     int fractional_part = value_local & fractional_mask;
//     int integer_part = fixed.toInt();
//     std::string buf;
//     buf = std::to_string(integer_part) + "." + std::to_string(fractional_part);
//     // std::cout << buf << std::endl;
//     return (buf);
// }
