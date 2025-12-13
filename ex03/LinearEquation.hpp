#ifndef LINEAR_EQUATION_HPP
#define LINEAR_EQUATION_HPP

#include <Line.hpp>
#include <Point.hpp>

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

#endif
