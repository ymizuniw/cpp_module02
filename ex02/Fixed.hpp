#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

class Fixed
{
    private:
        int value_;
        static const int fbits_=8;
    public:
        Fixed();
        Fixed(const Fixed &src); 
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed   &operator=(const Fixed &other);
        bool    operator>(const Fixed &other);
        bool    operator<(const Fixed &other);
        bool    operator>=(const Fixed &other);
        bool    operator<=(const Fixed &other);
        bool    operator==(const Fixed &other);
        bool    operator!=(const Fixed &other);
        Fixed   &operator+(const Fixed &other);
        Fixed   &operator-(const Fixed &other);
        Fixed   &operator*(const Fixed &other);
        Fixed   &operator/(const Fixed &other);
        Fixed   &operator++(void);
        Fixed   &operator--(void);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        static Fixed &min(Fixed &f1, Fixed &f2);
        static Fixed &min(Fixed const &f1, Fixed const &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static Fixed &max(Fixed const &f1, Fixed const &f2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif