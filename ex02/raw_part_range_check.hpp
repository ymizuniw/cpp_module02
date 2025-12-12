#ifndef RAW_OVERFLOW_HPP
#define RAW_OVERFLOW_HPP

typedef enum e_range
{
  CLEAR,
  INT_PART_OVERFLOW,
  INT_PART_UNDERFLOW,
  RAW_PART_OVERFLOW,
  RAW_PART_UNDERFLOW
} t_range;

typedef t_range (*check_raw_range_t)(int value1, int value2, int fbits);

t_range raw_part_add(int value1, int value2, int fbits);
t_range raw_part_subtract(int value1, int value2, int fbits);
t_range raw_part_multi(int value1, int value2, int fbits);
t_range raw_part_devide(int value1, int value2, int fbits);

t_range raw_part_prefix_increment(int value1, int value2, int fbits);
t_range raw_part_postfix_increment(int value1, int value2, int fbits);
t_range raw_part_prefix_decrement(int value1, int value2, int fbits);
t_range raw_part_postfix_decrement(int value1, int value2, int fbits);

#endif
