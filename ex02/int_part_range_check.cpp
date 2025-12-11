#include <int_part_range_check.hpp>
#include <iostream>

bool int_part_add(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1>0 && value2>0)
    {
        if (value1 > INT_PART_OFLIMIT - value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
    }
    else if (value1 < 0 && value2 <0)
    {
        if (value1 < INT_PART_UFLIMIT - value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
    }
    return (false);
}

bool int_part_subtract(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
   if (value1 < 0 && value2 > 0)
   {
        if (value1  < INT_PART_UFLIMIT + value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
   }
   else if (value1 > 0 && value2 < 0)
   {
        if (value1  > INT_PART_OFLIMIT + value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
   }
    return (false);
}

bool int_part_multi(int value1, int value2)
{
    uint64_t    n;
    uint64_t    v1;
    uint64_t    v2;
    int         sign1=1;
    int         sign2=1;

    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1<0)
        sign1 = 0;
    if (value2<0)
        sign2 = 0;
    if (sign1 && sign2)
    {
        v1 = value1;
        v2 = value2;
        n = v1 * v2;
        if (n>INT_PART_OFLIMIT)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
    }
    else if (sign1 && !sign2)
    {
        v1 = value1;
        v2 = -value2;
        n = v1 * v2;
        if (n>INT_PART_OFLIMIT)
        {
          std::cerr << "underflow: " << std::endl;
          return (true);  
        }
    }
    else if (!sign1 && sign2)
    {
        v1 = -value1;
        v2 = value2;
        n = v1 * v2;
        if (n>INT_PART_OFLIMIT)
        {
          std::cerr << "underflow: " << std::endl;
          return (true);  
        }
    }
    else if (!sign1 && !sign2)
    {
        v1 = -value1;
        v2 = -value2;
        n = v1 * v2;
        if (n>INT_PART_OFLIMIT)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }  
    }
    return false;
}

bool int_part_devide(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    return false;
}

bool int_part_prefix_increment(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1 + 1>INT_PART_OFLIMIT)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool int_part_postfix_increment(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    
    if (value1 + 1>INT_PART_OFLIMIT)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool int_part_prefix_decrement(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1 - 1 < INT_PART_UFLIMIT)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool int_part_postfix_decrement(int value1, int value2)
{
    if (value1 < INT_PART_UFLIMIT || value1 > INT_PART_OFLIMIT || value2 < INT_PART_UFLIMIT || value2 > INT_PART_OFLIMIT)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1 - 1 < INT_PART_UFLIMIT)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}
