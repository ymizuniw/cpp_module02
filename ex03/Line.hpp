#ifndef LINE_HPP
#define LINE_HPP

#include <Fixed.hpp>

class Line {
private:
  Fixed cex_;
  Fixed x_;
  Fixed cey_;
  Fixed y_;
  Fixed C_;

public:
  Line(Fixed const cex, Fixed const x, Fixed const cey, Fixed const y);
  Line(Line const &other);
  Line const &operator=(Line const &other);
  ~Line(void);
  Fixed getCex(void) const;
  Fixed getCey(void) const;
  Fixed getX(void) const;
  Fixed getY(void) const;
  Fixed getC(void) const;
};

#endif
