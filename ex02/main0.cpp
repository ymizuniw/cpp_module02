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
    std::cout << "toFloat(): " << f << std::endl;
    std::cout << "" << f.toInt() << std::endl;
}

int main(void)
{
    int sigMax = 8388607;
    int sigMin = -8388608;

    std::cout << "Constructor Integer for Calculation" << std::endl;
    Fixed zero(0);
    Fixed one(1);
    Fixed two(2);
    Fixed three(3);
    // Fixed four(4);
    // Fixed five(5);
    // Fixed six(6);

    std::cout << "Constructor Boundary Check" << std::endl;
    Fixed a(sigMax);
    Fixed b(sigMin);
    Fixed c(std::numeric_limits<int>::max());
    Fixed d(std::numeric_limits<int>::min());
    Fixed e(sigMax/2);
    Fixed f(sigMin/2);

    std::cout << "Print Constructed Threshold Values" << std::endl;
    print_fixed_status(a);
    print_fixed_status(b);
    print_fixed_status(c);
    print_fixed_status(d);
    print_fixed_status(e);
    print_fixed_status(f);

    //addition, subtracting test
    std::cout << "\nsigMax + one: " << std::endl;
    Fixed a1 = a + one;
    print_fixed_status(a1);

    std::cout << "\nsigMin - one: " << std::endl;
    Fixed a2 = b - one;
    print_fixed_status(a2);

    std::cout << "\nintMax + 1: " << std::endl;
    Fixed a3 = c + one;
    print_fixed_status(a3);
    
    std::cout << "\nintMin - 1: " << std::endl;
    Fixed a4 = d - one;
    print_fixed_status(a4);
    
    std::cout << "\nsigMax/2 + sigMax/2: " << std::endl;
    Fixed a5 = e + e;
    print_fixed_status(a5);
    
    std::cout << "\nsigMax/2 + sigMax/2 + 1: " << std::endl;
    Fixed a6 = a5 + one;
    print_fixed_status(a6);

    std::cout << "\nsigMin/2 + sigMin/2: " << std::endl;
    Fixed a7 = f + f;
    print_fixed_status(a7);

    std::cout << "\nsigMin/2 + sigMin/2 - 1: " << std::endl;
    Fixed a8 = a7 - one;
    print_fixed_status(a8);

    //multipling, deviding test
    std::cout << "\nsigMax * 1: " << std::endl;
    Fixed m1 = a * one;
    print_fixed_status(m1);

    std::cout << "\nsigMin * 1: " << std::endl;
    Fixed m2 = b * one;
    print_fixed_status(m2);
    
    std::cout << "\nsigMax * 2: " << std::endl;
    Fixed m1_1 = a * two;
    print_fixed_status(m1_1);

    std::cout << "\nsigMin * 2: " << std::endl;
    Fixed m2_1 = b * two;
    print_fixed_status(m2_1);

    std::cout << "\nintMax * 1: " << std::endl;
    Fixed m1_2 = c * one;
    print_fixed_status(m1_2);

    std::cout << "\nintMin * 1: " << std::endl;
    Fixed m2_2 = d * one;
    print_fixed_status(m2_2);

    std::cout << "\nintMax * 2: " << std::endl;
    Fixed m1_3 = c * two;
    print_fixed_status(m1_3);

    std::cout << "\nintMin * 2: " << std::endl;
    Fixed m2_3 = b * two;
    print_fixed_status(m2_3);

    std::cout << "\nsigMax/sigMax: " << std::endl;
    Fixed d1 = a / a;
    print_fixed_status(d1);

    std::cout << "\nsigMax/sigMin: " << std::endl;
    Fixed d2 = a / b;
    print_fixed_status(d2);

    std::cout << "\nsigMin/sigMin: " << std::endl;
    Fixed d3 = b / b;
    print_fixed_status(d3);

    std::cout << "\nsigMin/sigMax: " << std::endl;
    Fixed d4 = b / a;
    print_fixed_status(d4);

    std::cout << "\n1/0: " << std::endl;
    Fixed d5 = one / zero;
    std::cout << one/zero << std::endl;
    std::cout << d5 << std::endl;
    print_fixed_status(d5);

    std::cout << "\n0/0: " << std::endl;
    Fixed d6 = zero/zero;
    print_fixed_status(d6);

    std::cout << "\n0/1: " << std::endl;
    Fixed d7 = zero/one;
    print_fixed_status(d7);    
    return (0);
}
