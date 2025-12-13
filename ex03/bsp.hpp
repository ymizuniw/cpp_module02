#ifndef BSP_HPP
#define BSP_HPP

#include <Fixed.hpp>
#include <Point.hpp>

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
  Fixed getCex(void);
  Fixed getCey(void);
  Fixed getX(void);
  Fixed getY(void);
  Fixed getC(void);
};

Fixed Line::getCex(void) { return (cex_); }
Fixed Line::getCey(void) { return (cey_); }
Fixed Line::getX(void) { return (x_); }
Fixed Line::getY(void) { return (y_); }
Fixed Line::getC(void) { return (C_); }

class LinearEquation {
private:
  Line l1_;
  Line l2_;

public:
  LinearEquation(Line l1, Line l2);
  LinearEquation(LinearEquation const &other);
  LinearEquation const &operator=(LinearEquation const &other);
  ~LinearEquation(void);
  Point solve(void);
};

Point LinearEquation::solve(void) {
  // if a==0; return?
  Fixed minus = Fixed(-1);
  Fixed a = l1_.getCex();
  Fixed b = l1_.getX();
  Fixed c = l1_.getC();
  Fixed d = l2_.getCex();
  Fixed e = l2_.getX();
  Fixed f = l2_.getC();

  Fixed af = a * f;
  Fixed cd = c * d;
  Fixed ae = a * e;
  Fixed bd = b * d;

  Fixed numerator1 = (af - cd) / (ae - bd);
  Fixed numerator2 = numerator1 * b - c;
  Fixed x = numerator2 / a;
  Fixed y = minus * numerator1;
  Point solution(x, y);
}

//  Numerator、「分母」は Denominator
#endif

// x = [ {(af-cd)/(ae-bd)}*b - c]/a;
// y = - {(af-cd)/(ae-bd)}
