#include <Point.hpp>

Point::Point(void) : x_(0), y_(0) {
  std::cout << "Point::zero init Constructor called" << std::endl;
}

Point::Point(float const x, float const y) : x_(x), y_(y) {
  std::cout << "Point::float init Constructor called" << std::endl;
}

Point::Point(Fixed const x, Fixed const y) : x_(x), y_(y) {
  std::cout << "Point::fixed init Constructor called" << std::endl;
}

Point::~Point(void) {
  std::cout << "Point::Default Destructor called" << std::endl;
}

Point::Point(Point const &other) : x_(other.x_), y_(other.y_) {
  std::cout << "Point::Copy Constructor called" << std::endl;
}

Point &Point::operator=(Point const &other) {
  (void)other;
  return (*this);
}

Fixed Point::getX(void) const { return (x_); }

Fixed Point::getY(void) const { return (y_); }
