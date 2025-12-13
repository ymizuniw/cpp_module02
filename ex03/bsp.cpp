#include <Fixed.hpp>
#include <Line.hpp>
#include <LinearEquation.hpp>
#include <Point.hpp>

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  // if vertex or edge
  // return false
  Fixed minus(-1);
  // in out judgement
  Fixed trend1 = ((a.getY() - b.getY())) / ((a.getX() - b.getX()));
  Fixed trend2 = ((b.getY() - c.getY())) / ((b.getX() - c.getX()));
  Fixed trend3 = ((c.getY() - a.getY())) / ((c.getX() - a.getX()));

  // ax + by + c = 0

  /*
    1. construct line 1, 2, 3
  */
  //   Line l1();
  //   Line l2();
  //   Line l3();

  /*
    3.seek X range
  */

  /*
    5.move paralell to origin point
  */

  /*
    6.solve y = 0 for each line.
  */

  /*
    7.if different two solutions have different sign x? then return true; else
    return false;
  */
}