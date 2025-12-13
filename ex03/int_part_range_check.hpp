#ifndef INT_PART_OVERFLOW_HPP
#define INT_PART_OVERFLOW_HPP

#define INT_PART_UFLIMIT -8388608
#define INT_PART_OFLIMIT 8388607

typedef enum e_range { CLEAR, INT_PART_OVERFLOW, INT_PART_UNDERFLOW } t_range;

typedef t_range (*check_raw_range)(int value1, int value2, int fbits);

t_range int_part_add(int value1, int value2, int fbits);
t_range int_part_subtract(int value1, int value2, int fbits);
t_range int_part_multi(int value1, int value2, int fbits);
t_range int_part_devide(int value1, int value2, int fbits);

t_range int_part_prefix_increment(int value1, int value2, int fbits);
t_range int_part_postfix_increment(int value1, int value2, int fbits);
t_range int_part_prefix_decrement(int value1, int value2, int fbits);
t_range int_part_postfix_decrement(int value1, int value2, int fbits);

#endif
