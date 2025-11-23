#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>

class Fixed
{
    private:
        int _value;
        static const int _fbits= 8;
    public:
        Fixed();
        Fixed(const Fixed &src); 
        ~Fixed();
        Fixed operator=(const Fixed &other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};


#endif