#include "Fixed.hpp"
#include <cmath>
#include <limits>
#include <int_part_range_check.hpp>
#include <raw_part_range_check.hpp>

void print_msg(std::string msg) { std::cout << msg << std::endl; }

Fixed::Fixed(void) : value_(0) {
  print_msg("Fixed::Default constructor called");
}

Fixed::Fixed(const Fixed &other) : value_(other.value_) {
  print_msg("Fixed::Copy constructor called");
}

Fixed::~Fixed(void) { print_msg("Fixed::destructor called"); }

Fixed &Fixed::operator=(Fixed const &other) {
  print_msg("Fixed::Copy assignment operator called");
  value_ = other.value_;
  return (*this);
}

int Fixed::getRawBits(void) const { return (value_); }

void Fixed::setRawBits(int const raw) {
  print_msg("Fixed::setRawBits() called");
  value_ = raw;
}

// ex01 NEW
/*
    if f == 3.1415;
    then value_ = 3.1415 * 2^8
*/
/*
    +8,388,607
    -8,388,608
*/

Fixed::Fixed(const int value) : value_(0) {
  if (value > INT_PART_OFLIMIT) {
    std::cerr << "int part overflow." << std::endl;
    return;
  } else if (value < INT_PART_UFLIMIT) {
    std::cerr << "int part underflow." << std::endl;
    return;
  }
  value_ = value * (1 << fbits_);
  print_msg("Fixed::int value constructor called");
}

// float -> int -> shift
Fixed::Fixed(const float value) {
  print_msg("Fixed::float value constructor called");
  if (static_cast<double>(value) > static_cast<double>(INT_PART_OFLIMIT)) {
    std::cerr << "intpart overflow." << std::endl;
    value_ = 0;
    return;
  } else if (static_cast<double>(value) <
             static_cast<double>(INT_PART_UFLIMIT)) {
    std::cerr << "intpart underflow." << std::endl;
    value_ = 0;
    return;
  }
  if (static_cast<double>(value) * (1 << fbits_) >
      static_cast<double>(std::numeric_limits<int>::max())) {
    std::cerr << "raw part overflow." << std::endl;
    value_ = 0;
    return;
  } else if (static_cast<double>(value) * (1 << fbits_) <
             static_cast<double>(std::numeric_limits<int>::min())) {
    std::cerr << "raw part underflow." << std::endl;
    value_ = 0;
    return;
  }
  float shift = value * (1 << fbits_);
  float round = roundf(shift);
  int cast = static_cast<int>(round);
  // std::cout << "Fixed::assignment constructor: float casted to " << cast <<
  // std::endl;
  value_ = cast;
}

/*
    if value_ == 0010 1010 0000 0000 ...
    then ret = (float)(value_ / 2^8)
*/
float Fixed::toFloat(void) const {
  // return ((float)value_ / (1 << fbits_));
  int divisor = (1 << fbits_);
  /*
      fbits_=8;
      divisor = 0000 0000 0000 0001 << 8;
      divisor = 0000 0001 0000 0000;
  */
  float inverse_divisor = 1.0f / static_cast<float>(divisor);
  /*
      inverse_divisor = 1.0000 / 256.0000
      inverse_divisor = 0.00390625;
  */
  float result = static_cast<float>(value_) * inverse_divisor;
  return (result);
}

int Fixed::toInt(void) const { return (value_ >> fbits_); }

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();
  return (os);
}

bool Fixed::operator>(const Fixed &other) const {
  if (value_ > other.value_)
    return (true);
  return (false);
}

bool Fixed::operator<(const Fixed &other) const {
  if (value_ < other.value_)
    return (true);
  return (false);
}

bool Fixed::operator>=(const Fixed &other) const {
  if (value_ >= other.value_)
    return (true);
  return (false);
}

bool Fixed::operator<=(const Fixed &other) const {
  if (value_ <= other.value_)
    return (true);
  return (false);
}

bool Fixed::operator==(const Fixed &other) const {
  if (value_ == other.value_)
    return (true);
  return (false);
}

bool Fixed::operator!=(const Fixed &other) const {
  if (value_ != other.value_)
    return (true);
  return (false);
}

// 8388608 threshold;
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed res;

  check_range_t check_range = int_part_add;
  if (check_range(value_ / (1 << fbits_), other.value_ / (1 << fbits_))) {
    res.value_ = 0;
    return (res);
  }
  check_raw_range_t check_raw_range = raw_part_add;
  if (check_raw_range(value_, other.value_, fbits_)) {
    res.value_ = 0;
    return (res);
  }
  res.value_ = value_ + other.value_;
  return (res);
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed res;

  check_range_t check_range = int_part_subtract;
  if (check_range(value_ / (1 << fbits_), other.value_ / (1 << fbits_))) {
    res.value_ = 0;
    return (res);
  }
  check_raw_range_t check_raw_range = raw_part_subtract;
  if (check_raw_range(value_, other.value_, fbits_)) {
    res.value_ = 0;
    return (res);
  }
  res.value_ = value_ - other.value_;
  return (res);
}

// typedef enum e_range
// {
//     UNDER_FLOW,
//     OVER_FLOW,
//     CLEAN
// } t_range;

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed res;

  check_range_t check_range = int_part_multi;
  if (check_range(value_ / (1 << fbits_), other.value_ / (1 << fbits_))) {
    res.value_ = 0;
    return (res);
  }
  check_raw_range_t check_raw_range = raw_part_multi;
  if (check_raw_range(value_, other.value_, fbits_)) {
    res.value_ = 0;
    return (res);
  }
  res.value_ = (value_ * other.value_) >> fbits_;
  return (res);
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed res;

  if (other.value_ == 0) {
    if (value_ == 0) {
      std::cerr << "0/0 occurred!" << std::endl;
      res.value_ = 0;
      return (res);
    }
    int sign = value_ > 0 ? 1 : 0;
    switch (sign) {
    case 1:
      res.value_ = INT_PART_OFLIMIT * (1 << fbits_);
      break;
    case 0:
      res.value_ = INT_PART_UFLIMIT * (1 << fbits_);
      break;
    }
    return (res);
  }
  check_range_t check_range = int_part_devide;
  if (check_range(value_ / (1 << fbits_), other.value_ / (1 << fbits_))) {
    res.value_ = 0;
    return (res);
  }
  check_raw_range_t check_raw_range = raw_part_devide;
  if (check_raw_range(value_, other.value_, fbits_)) {
    res.value_ = 0;
    return (res);
  }
  int64_t v1 = static_cast<int64_t>(value_) * (1 << fbits_);
  int64_t v2 = other.value_;
  int64_t n = v1 / v2;
  res.value_ = static_cast<int>(n);
  return (res);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);
  check_range_t check_range = int_part_postfix_increment;
  if (check_range(tmp.value_ / (1 << fbits_), 0)) {
    tmp.value_ = 0;
    return (tmp);
  }
  check_raw_range_t check_raw_range = raw_part_postfix_increment;
  if (check_raw_range(value_, 0, fbits_)) {
    tmp.value_ = 0;
    return (tmp);
  }
  value_ += 1;
  return (tmp);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);
  check_range_t check_range = int_part_postfix_decrement;
  if (check_range(tmp.value_ / (1 << fbits_), 0)) {
    tmp.value_ = 0;
    return (tmp);
  }
  check_raw_range_t check_raw_range = raw_part_postfix_decrement;
  if (check_raw_range(value_, 0, fbits_)) {
    tmp.value_ = 0;
    return (tmp);
  }
  value_ -= 1;
  return (tmp);
}

Fixed &Fixed::operator++(void) {
  check_range_t check_range = int_part_prefix_increment;
  if (check_range(value_ / (1 << fbits_), 0)) {
    value_ = 0;
    return (*this);
  }
  check_raw_range_t check_raw_range = raw_part_prefix_increment;
  if (check_raw_range(value_, 0, fbits_))
    value_ = 0;
  else
    value_ += 1;
  return (*this);
}

Fixed &Fixed::operator--(void) {
  check_range_t check_range = int_part_prefix_decrement;
  if (check_range(value_ / (1 << fbits_), 0)) {
    value_ = 0;
    return (*this);
  }
  check_raw_range_t check_raw_range = raw_part_prefix_decrement;
  if (check_raw_range(value_, 0, fbits_)) {
    value_ = 0;
    return (*this);
  }
  value_ -= 1;
  return (*this);
}

// if equal, return left operand
Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2) {
  if (f1 > f2)
    return (f2);
  return (f1);
}

// if equal, return left operand
Fixed const &Fixed::max(Fixed const &f1, Fixed const &f2) {
  if (f1 > f2)
    return (f1);
  return (f2);
}
