#include <Fixed.hpp>
#include <limits>

//overflow, threshold values validation check.
/*
    significand max: 8388607
    significand min: -8388608
    int max: INT_MAX
    int min: INT_MIN
    float significand max: numeric_limits<float>::max()
    float significand min: numeric_limits<float>::min()
    24bit signRev: 0x800000
*/

void print_fixed_status(Fixed &f)
{
    std::cout << "getRawBits(): " << f.getRawBits() << std::endl;
    std::cout << "toFloat(): " << f.toFloat() << std::endl;
    std::cout << "" << f.toInt() << std::endl;
}

int main(void)
{
    int sigMax = 8388607;
    int sigMin = -8388608;

    Fixed zero(0);
    Fixed one(1);
    Fixed two(2);
    Fixed three(3);
    // Fixed four(4);
    // Fixed five(5);
    // Fixed six(6);

    Fixed a(sigMax);
    Fixed b(sigMin);
    Fixed c(std::numeric_limits<int>::max());
    Fixed d(std::numeric_limits<int>::min());
    Fixed e(sigMax/2);
    Fixed f(sigMin/2);

    print_fixed_status(a);
    print_fixed_status(b);
    print_fixed_status(c);
    print_fixed_status(d);
    print_fixed_status(e);
    print_fixed_status(f);

    //addition, subtracting test
    std::cout << "sigMax + one: ";
    Fixed a1 = a + one;
    print_fixed_status(a1);

    std::cout << "sigMin - one: ";
    Fixed a2 = b - one;
    print_fixed_status(a2);

    std::cout << "intMax + 1: ";
    Fixed a3 = c + one;
    print_fixed_status(a3);
    
    std::cout << "intMin - 1: ";
    Fixed a4 = d - one;
    print_fixed_status(a4);
    
    std::cout << "sigMax/2 + sigMax/2: ";
    Fixed a5 = e + e;
    print_fixed_status(a5);
    
    std::cout << "sigMax/2 + sigMax/2 + 1: ";
    Fixed a6 = a5 + one;
    print_fixed_status(a6);

    std::cout << "sigMin/2 + sigMin/2: ";
    Fixed a7 = f + f;
    print_fixed_status(a7);

    std::cout << "sigMin/2 + sigMin/2 - 1: ";
    Fixed a8 = a7 - one;
    print_fixed_status(a8);

    //multipling, deviding test
    std::cout << "sigMax * 1: ";
    Fixed m1 = a * one;
    print_fixed_status(m1);

    std::cout << "sigMin * 1: ";
    Fixed m2 = b * one;
    print_fixed_status(m2);
    
    std::cout << "sigMax * 2: ";
    Fixed m1_1 = a * two;
    print_fixed_status(m1_1);

    std::cout << "sigMin * 2: ";
    Fixed m2_1 = b * two;
    print_fixed_status(m2_1);

    std::cout << "intMax * 1: ";
    Fixed m1_2 = c * one;
    print_fixed_status(m1_2);

    std::cout << "intMin * 1: ";
    Fixed m2_2 = d * one;
    print_fixed_status(m2_2);

    std::cout << "intMax * 2: ";
    Fixed m1_3 = c * two;
    print_fixed_status(m1_3);

    std::cout << "intMin * 2: ";
    Fixed m2_3 = b * two;
    print_fixed_status(m2_3);

    std::cout << "sigMax/sigMax: ";
    Fixed d1 = a / a;
    print_fixed_status(d1);

    std::cout << "sigMax/sigMin: ";
    Fixed d2 = a / b;
    print_fixed_status(d2);

    std::cout << "sigMin/sigMin: ";
    Fixed d3 = b / b;
    print_fixed_status(d3);

    std::cout << "sigMin/sigMax: ";
    Fixed d4 = b / a;
    print_fixed_status(d4);

    std::cout << "1/0: ";
    Fixed d5 = one / zero;
    print_fixed_status(d5);

    std::cout << "0/0: ";
    Fixed d6 = zero/zero;
    print_fixed_status(d6);

    std::cout << "0/1: ";
    Fixed d7 = zero/one;
    print_fixed_status(d7);

    
}