#include <Fixed.hpp>
#include <Point.hpp>
#include <iostream>

long AreaSize(const Point &u, const Point &v) {
  long tmp = static_cast<long>(u.getX().getRawBits()) *
                 static_cast<long>(v.getY().getRawBits()) -
             static_cast<long>(u.getY().getRawBits()) *
                 static_cast<long>(v.getX().getRawBits());
  if (tmp < 0)
    return (-tmp);
  return (tmp);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {

  Point ap(a.getX() - p.getX(), a.getY() - p.getY());
  Point bp(b.getX() - p.getX(), b.getY() - p.getY());
  Point cp(c.getX() - p.getX(), c.getY() - p.getY());

  Point bp_ap(bp.getX() - ap.getX(), bp.getY() - ap.getY());
  Point cp_ap(cp.getX() - ap.getX(), cp.getY() - ap.getY());

  long S = AreaSize(bp_ap, cp_ap);
  long S1 = AreaSize(ap, bp);
  long S2 = AreaSize(bp, cp);
  long S3 = AreaSize(cp, ap);
  if (S1 == 0 || S2 == 0 || S3 == 0)
    return false;
  return (S1 + S2 + S3 == S);
}
