#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>

class Fixed
{
    private:
        int                 value_;
        static const int    fbits_ = 8;
    public:
                Fixed();
                Fixed(const Fixed &other); 
        Fixed   &operator=(const Fixed &other);
                ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

void            print_msg(std::string msg);

#endif
