#ifndef FIXED_OVERFLOW_HPP
#define FIXED_OVERFLOW_HPP

// #include <iostream>
// #include <limits>

typedef bool (*check_range_t)(int value1, int value2);

#define INT_PART_UFLIMIT -8388608
#define INT_PART_OFLIMIT 8388607

bool int_part_add(int value1, int value2);
bool int_part_subtract(int value1, int value2);
bool int_part_multi(int value1, int value2);
bool int_part_devide(int value1, int value2);
bool int_part_prefix_increment(int value1, int value2);
bool int_part_postfix_increment(int value1, int value2);
bool int_part_prefix_decrement(int value1, int value2);
bool int_part_postfix_decrement(int value1, int value2);

#endif
