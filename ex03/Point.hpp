#ifndef POINT_HPP
#define POINT_HPP

#include <Fixed.hpp>

class Point {
private:
  Fixed const x_;
  Fixed const y_;

public:
  Point(void);
  Point(float const x, float const y);
  Point(Fixed x, Fixed y);
  ~Point(void);
  Point(Point const &other);
  Point &operator=(Point const &other);
  Fixed getX() const;
  Fixed getY() const;
};

#endif
