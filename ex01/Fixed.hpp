#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
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
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

#endif
