#include "Fixed.hpp"
#include <iostream>

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
  value_ = other.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const {
  print_msg("Fixed::getRawBits() called");
  return (value_);
}

void Fixed::setRawBits(int const raw) {
  print_msg("Fixed::setRawBits() called");
  value_ = raw;
}
