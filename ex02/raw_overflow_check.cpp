#include <iostream>
#include <limits>

bool (*raw_overflow)(int value1, int value2);
// 549,755,813,888 INT_MAX * 256
// 9,223,372,036,854,775,808 2 ^ 63 uint64_t
bool add(int value1, int value2)
{
    if (value1>0 && value2>0)
    {
        if (value1 > INT_MAX - value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
    }
    else if (value1 < 0 && value2 <0)
    {
        if (value1 < INT_MIN - value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
    }
    return (false);
}

bool subtract(int value1, int value2)
{
   if (value2 > 0)
   {
        if (value1  < INT_MIN + value2)
        {
            std::cerr << "underflow: " << std::endl;
            return (true);
        }
   }
   else if (value2 < 0)
   {
        if (value1  > INT_MAX + value2)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
   }
    return (false);
}

bool multi(int value1, int value2)
{
    uint64_t    n;
    uint64_t    v1;
    uint64_t    v2;
    int         sign1=1;
    int         sign2=1;

    if (value1<0)
        sign1 = 0;
    if (value2<0)
        sign2 = 0;
    if (sign1 && sign2)
    {
        v1 = value1;
        v2 = value2;
        n = v1 * v2;
        if (n/256>INT_MAX)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }
    }
    else if (sign1 && !sign2)
    {
        v1 = value1;
        v2 = static_cast<uint64_t>(-static_cast<int64_t>(value2));
        n = v1 * v2;
        if (n/256>INT_MAX+1)
        {
          std::cerr << "underflow: " << std::endl;
          return (true);  
        }
    }
    else if (!sign1 && sign2)
    {
        v1 = static_cast<uint64_t>(-static_cast<int64_t>(value1));
        v2 = value2;
        n = v1 * v2;
        if (n/256>INT_MAX+1)
        {
          std::cerr << "underflow: " << std::endl;
          return (true);  
        }
    }
    else if (!sign1 && !sign2)
    {
        v1 = static_cast<uint64_t>(-static_cast<int64_t>(value1));
        v2 = static_cast<uint64_t>(-static_cast<int64_t>(value2));
        n = v1 * v2;
        if (n/256>INT_MAX)
        {
            std::cerr << "overflow: " << std::endl;
            return (true);
        }  
    }
    return false;
}

bool devide(int value1, int value2, int fbits)
{
    return false;
}

bool prefix_increment(int value1, int value2)
{
    (void)value2;
    if (value1 + 1>INT_MAX)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool postfix_increment(int value1, int value2)
{
    (void)value2;
    if (value1 + 1>INT_MAX)
    {
        std::cerr << "overflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool prefix_decrement(int value1, int value2)
{
    (void)value2;
    if (value1 - 1 < INT_MIN)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}

bool postfix_decrement(int value1, int value2)
{
    (void)value2;
    if (value1 - 1 < INT_MIN)
    {
        std::cerr << "underflow: " << std::endl;
        return (true);
    }
    return (false);
}
