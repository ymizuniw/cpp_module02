#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <iomanip>

//static member is unique, and all object has it in common.
class Fixed
{
    private:
        int value_;
        static constexpr int fbits_=8;
    public:
        Fixed();
        Fixed(const Fixed &src); 
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed   &operator=(const Fixed &other);
        bool    operator>(const Fixed &other) const;
        bool    operator<(const Fixed &other) const;
        bool    operator>=(const Fixed &other) const;
        bool    operator<=(const Fixed &other) const;
        bool    operator==(const Fixed &other) const;
        bool    operator!=(const Fixed &other) const;
        Fixed   &operator+(const Fixed &other) const;
        Fixed   &operator-(const Fixed &other) const;
        Fixed   &operator*(const Fixed &other) const;
        Fixed   &operator/(const Fixed &other) const;
        //read the value of the object first, and subeffect is applied later.
        Fixed   operator++(int);
        Fixed   operator--(int);
        Fixed   &operator++(void);
        Fixed   &operator--(void);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        static Fixed const &min(Fixed const &f1, Fixed const &f2);
        static Fixed const &max(Fixed const &f1, Fixed const &f2);
};

bool    (*overflow_check)(int value1, int value2, int negative_limit, int positive_limit);

#define FIXED_UFLIMIT -8388608
#define FIXED_OFLIMIT 8388608

bool add(int value1, int value2, int negative_limit, int positive_limit);
bool subtract(int value1, int value2, int negative_limit, int positive_limit);
bool multi(int value1, int value2, int negative_limit, int positive_limit);
bool devide(int value1, int value2, int negative_limit, int positive_limit);

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif
