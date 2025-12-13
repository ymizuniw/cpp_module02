#include <LinearEquation.hpp>

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
  return solution;
}
