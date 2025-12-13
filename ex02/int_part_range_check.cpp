#include <int_part_range_check.hpp>
#include <iostream>
#include <stdint.h>

// 549,755,813,888 INT_PART_OFLIMIT * (1<<fbits)
// 9,223,372,036,854,775,808 2 ^ 63 uint64_t
t_range int_part_add(int value1, int value2, int fbits) {
  int64_t n;
  int64_t v1;
  int64_t v2;

  v1 = value1;
  v2 = value2;
  n = v1 + v2;
  int64_t eval = n >> fbits;
  if (eval > INT_PART_OFLIMIT) {
    std::cerr << "overflow: " << value1 << " + " << value2 << std::endl;
    return (INT_PART_OVERFLOW);
  } else if (eval < INT_PART_UFLIMIT) {
    std::cerr << "underflow: " << std::endl;
    return (INT_PART_UNDERFLOW);
  }
  return (CLEAR);
}

t_range int_part_subtract(int value1, int value2, int fbits) {
  int64_t v1 = value1;
  int64_t v2 = value2;
  int64_t n = v1 - v2;
  int64_t eval = n >> fbits;
  if (eval < INT_PART_UFLIMIT) {
    std::cerr << "underflow: " << value1 << " - " << value2 << std::endl;
    return (INT_PART_UNDERFLOW);
  } else if (eval > INT_PART_OFLIMIT) {
    std::cerr << "overflow: " << std::endl;
    return (INT_PART_OVERFLOW);
  }
  return (CLEAR);
}

t_range int_part_multi(int value1, int value2, int fbits) {
  int64_t n;
  int64_t v1;
  int64_t v2;

  v1 = value1;
  v2 = value2;
  n = v1 * v2;
  int64_t eval = n >> (fbits * 2);
  if (eval > INT_PART_OFLIMIT) {
    std::cerr << "overflow: " << value1 << " * " << value2 << std::endl;
    return (INT_PART_OVERFLOW);
  } else if (eval < INT_PART_UFLIMIT) {
    std::cerr << "underflow: " << std::endl;
    return (INT_PART_UNDERFLOW);
  }
  return (CLEAR);
}

t_range int_part_devide(int value1, int value2, int fbits) {
  (void)value1;
  (void)value2;
  (void)fbits;
  return (CLEAR);
}

t_range int_part_prefix_increment(int value1, int value2, int fbits) {
  (void)value2;
  if (value1 == ((INT_PART_OFLIMIT << fbits) | ((1 << fbits) - 1))) {
    std::cerr << "overflow: " << "++" << value1 << std::endl;
    return (INT_PART_OVERFLOW);
  }
  return (CLEAR);
}

t_range int_part_postfix_increment(int value1, int value2, int fbits) {
  (void)value2;
  if (value1 == ((INT_PART_OFLIMIT << fbits) | ((1 << fbits) - 1))) {
    std::cerr << "overflow: " << value1 << "++" << std::endl;
    return (INT_PART_OVERFLOW);
  }
  return (CLEAR);
}

t_range int_part_prefix_decrement(int value1, int value2, int fbits) {
  (void)value2;
  const int32_t RAW_MIN =
      static_cast<int32_t>(-(static_cast<int64_t>(1) << (23 + fbits)));

  if (value1 == RAW_MIN) {
    std::cerr << "underflow: " << "--" << value1 << std::endl;
    return (INT_PART_UNDERFLOW);
  }
  return (CLEAR);
}

t_range int_part_postfix_decrement(int value1, int value2, int fbits) {
  (void)value2;
  const int32_t RAW_MIN =
      static_cast<int32_t>(-(static_cast<int64_t>(1) << (23 + fbits)));
  if (value1 == RAW_MIN) {
    std::cerr << "underflow: " << "--" << value1 << std::endl;
    return (INT_PART_UNDERFLOW);
  }
  return (CLEAR);
}
