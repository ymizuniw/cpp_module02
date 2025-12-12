#ifndef RAW_OVERFLOW_HPP
#define RAW_OVERFLOW_HPP

typedef bool (*check_raw_range_t)(int value1, int value2, int fbits);

bool raw_part_add(int value1, int value2, int fbits);
bool raw_part_subtract(int value1, int value2, int fbits);
bool raw_part_multi(int value1, int value2, int fbits);
bool raw_part_devide(int value1, int value2, int fbits);

bool raw_part_prefix_increment(int value1, int value2, int fbits);
bool raw_part_postfix_increment(int value1, int value2, int fbits);
bool raw_part_prefix_decrement(int value1, int value2, int fbits);
bool raw_part_postfix_decrement(int value1, int value2, int fbits);

#endif
