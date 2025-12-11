#include <iostream>
#include <limits>

bool add(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    if (value1>0 && value2>0)
    {
        if (value1 > positive_limit - value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
    }
    else if (value1 < 0 && value2 <0)
    {
        if (value1 > negative_limit - value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
    }
    return (false);
}

bool subtract(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
   if (value1 < 0 && value2 > 0)
   {
        if (value1  < negative_limit + value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
   }
   else if (value1 > 0 && value2 < 0)
   {
        if (value1  > positive_limit + value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
   }
    return (false);
}

bool multi(int value1, int value2, int negative_limit, int positive_limit)
{
    uint64_t    n;
    uint64_t    v1;
    uint64_t    v2;
    int         sign1=1;
    int         sign2=1;

    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
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
        if (n>positive_limit)
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
        if (n>positive_limit)
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
        if (n>positive_limit)
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
        if (n>positive_limit)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }  
    }
    return false;
}

bool devide(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    return false;
}

bool prefix_increment(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    (void)value2;
    (void)negative_limit;
    if (value1 + 1>positive_limit)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}


bool postfix_increment(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    (void)value2;
    (void)negative_limit;
    
    if (value1 + 1>positive_limit)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool prefix_decrement(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    (void)value2;
    (void)positive_limit;
    if (value1 - 1 < negative_limit)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool postfix_decrement(int value1, int value2, int negative_limit, int positive_limit)
{
    if (value1 < negative_limit || value1 > positive_limit || value2 < negative_limit || value2 > positive_limit)
    {
        std::cerr << "given value includes out of range +-2^23-1 of Fixed class." << std::endl;
        return (true);
    }
    (void)value2;
    (void)positive_limit;
    if (value1 - 1 < negative_limit)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}
