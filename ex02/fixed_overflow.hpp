#ifndef FIXED_OVERFLOW_HPP
#define FIXED_OVERFLOW_HPP

bool    (*fixed_overflow)(int value1, int value2, int negative_limit, int positive_limit);

#define FIXED_UFLIMIT -8388608
#define FIXED_OFLIMIT 8388608

bool add(int value1, int value2, int negative_limit, int positive_limit);
bool subtract(int value1, int value2, int negative_limit, int positive_limit);
bool multi(int value1, int value2, int negative_limit, int positive_limit);
bool devide(int value1, int value2, int negative_limit, int positive_limit);
bool prefix_increment(int value1, int value2, int negative_limit, int positive_limit);
bool postfix_increment(int value1, int value2, int negative_limit, int positive_limit);
bool prefix_decrement(int value1, int value2, int negative_limit, int positive_limit);
bool postfix_decrement(int value1, int value2, int negative_limit, int positive_limit);

#endif
