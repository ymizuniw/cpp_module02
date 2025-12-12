#include <iostream>
#include <limits>
#include <stdint.h>

// 549,755,813,888 std::numeric_limits<int>::max() * (1<<fbits)
// 9,223,372,036,854,775,808 2 ^ 63 uint64_t
bool raw_part_add(int value1, int value2, int fbits) {
  (void)fbits;
  if (value1 > 0 && value2 > 0) {
    if (value1 > std::numeric_limits<int>::max() - value2) {
      std::cerr << "overflow: " << std::endl;
      return (true);
    }
  } else if (value1 < 0 && value2 < 0) {
    if (value1 < std::numeric_limits<int>::min() - value2) {
      std::cerr << "underflow: " << std::endl;
      return (true);
    }
  }
  return (false);
}

bool raw_part_subtract(int value1, int value2, int fbits) {
  (void)fbits;
  if (value2 > 0) {
    if (value1 < std::numeric_limits<int>::min() + value2) {
      std::cerr << "underflow: " << std::endl;
      return (true);
    }
  } else if (value2 < 0) {
    if (value1 > std::numeric_limits<int>::max() + value2) {
      std::cerr << "overflow: " << std::endl;
      return (true);
    }
  }
  return (false);
}

bool raw_part_multi(int value1, int value2, int fbits) {
  uint64_t n;
  uint64_t v1;
  uint64_t v2;
  uint64_t int_max = static_cast<uint64_t>(std::numeric_limits<int>::max());
  int sign1 = 1;
  int sign2 = 1;

  if (value1 < 0)
    sign1 = 0;
  if (value2 < 0)
    sign2 = 0;
  if (sign1 && sign2) {
    v1 = value1;
    v2 = value2;
    n = v1 * v2;
    if (n / (1 << fbits) > int_max) {
      std::cerr << "overflow: " << std::endl;
      return (true);
    }
  } else if (sign1 && !sign2) {
    v1 = value1;
    v2 = static_cast<uint64_t>(-static_cast<int64_t>(value2));
    n = v1 * v2;
    if (n / (1 << fbits) > int_max + 1) {
      std::cerr << "underflow: " << std::endl;
      return (true);
    }
  } else if (!sign1 && sign2) {
    v1 = static_cast<uint64_t>(-static_cast<int64_t>(value1));
    v2 = value2;
    n = v1 * v2;
    if (n / (1 << fbits) > int_max + 1) {
      std::cerr << "underflow: " << std::endl;
      return (true);
    }
  } else if (!sign1 && !sign2) {
    v1 = static_cast<uint64_t>(-static_cast<int64_t>(value1));
    v2 = static_cast<uint64_t>(-static_cast<int64_t>(value2));
    n = v1 * v2;
    if (n / (1 << fbits) > int_max) {
      std::cerr << "overflow: " << std::endl;
      return (true);
    }
  }
  return false;
}

bool raw_part_devide(int value1, int value2, int fbits) {
  (void)value1;
  (void)value2;
  (void)fbits;
  return false;
}

bool raw_part_prefix_increment(int value1, int value2, int fbits) {
  (void)value2;
  (void)fbits;
  if (value1 + 1 > std::numeric_limits<int>::max()) {
    std::cerr << "overflow: " << std::endl;
    return (true);
  }
  return (false);
}

bool raw_part_postfix_increment(int value1, int value2, int fbits) {
  (void)value2;
  (void)fbits;
  if (value1 + 1 > std::numeric_limits<int>::max()) {
    std::cerr << "overflow: " << std::endl;
    return (true);
  }
  return (false);
}

bool raw_part_prefix_decrement(int value1, int value2, int fbits) {
  (void)value2;
  (void)fbits;
  if (value1 - 1 < std::numeric_limits<int>::min()) {
    std::cerr << "underflow: " << std::endl;
    return (true);
  }
  return (false);
}

bool raw_part_postfix_decrement(int value1, int value2, int fbits) {
  (void)value2;
  (void)fbits;
  if (value1 - 1 < std::numeric_limits<int>::min()) {
    std::cerr << "underflow: " << std::endl;
    return (true);
  }
  return (false);
}
