
#include "Fixed.hpp"

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

Fixed::Fixed(const float f): value_(static_cast<int>(roundf(f*(1<<fbits_))))
{
    std::cout << "Float constructur called" << std::endl;
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
    return (static_cast<float>(value_) / static_cast<float>(1 << fbits_));

    // int shift = value_<<0x08;
    // float res = static_cast<float>(shift);
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

bool Fixed::operator>(const Fixed &other) const
{
    if (value_>other.value_)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
    if (value_<other.value_)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
    if (value_>=other.value_)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
    if (value_>=other.value_)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
    if (value_==other.value_)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
    if (value_>=other.value_)
        return (true);
    return (false);
}

Fixed   &Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.value_ = value_ + other.value_;
    return (res);
}

Fixed   &Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.value_ = value_ - other.value_;
    return (res);
}

Fixed   &Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    res.value_ = value_ * other.value_;
    return (res);
}

Fixed   &Fixed::operator/(const Fixed &other) const
{
    Fixed res;
    res.value_ = value_ / other.value_;
    return (res);
}

//postfix increment
Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    value_+=(1<<fbits_);
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);
    value_-+(1<<fbits_);
    return (tmp);
}

//prefix increment
Fixed   &Fixed::operator++(void)
{
    std::cerr <<"++ operator called: before:" << value_;
    value_+=(1<<fbits_);
    std::cerr <<"++ operator called: after:" <<  value_;
    return (*this);
}

Fixed   &Fixed::operator--(void)
{
    std::cerr <<"-- operator called: before:" << value_;
    value_-=(1<<fbits_);
    std::cerr <<"-- operator called: before:" << value_;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    int value_local = fixed.getRawBits();
    int fractional_mask = 0x0008;//32bit:0x0008
    int fractional_part = value_local & fractional_mask;
    int integer_part = fixed.toInt();
    std::string buf;
    buf = std::to_string(integer_part) + "." + std::to_string(fractional_part);
    os << buf;
    return (os);
}

static Fixed const &min(Fixed const &f1, Fixed const &f2)
{
    if (f1>f2)
        return (f2);
    return (f1);
}

static Fixed const &max(Fixed const &f1, Fixed const &f2)
{
    if (f1>f2)
        return (f1);
    return (f2);
}
