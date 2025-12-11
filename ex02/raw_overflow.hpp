#ifndef RAW_OVERFLOW_HPP
#define RAW_OVERFLOW_HPP

#include <limits>

bool (*raw_overflow)(int value1, int value2);

bool add(int value1, int value2);
bool subtract(int value1, int value2);
bool multi(int value1, int value2);
bool devide(int value1, int value2);

bool prefix_increment(int value1, int value2);
bool postfix_increment(int value1, int value2);
bool prefix_decrement(int value1, int value2);
bool postfix_decrement(int value1, int value2);

#endif
