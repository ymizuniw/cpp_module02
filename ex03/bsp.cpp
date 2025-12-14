#include <Point.hpp>

// twice of the real size
Fixed getAriaSize(Fixed x1, Fixed y2, Fixed x2, Fixed y1) {
  Fixed ariaSize = (x1 * y2 - x2 * y1);
  if (ariaSize < Fixed(0))
    return (Fixed(-1) * ariaSize);
  return (ariaSize);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {

  // Area Size
  Point bt0(b.getX() - a.getX(), b.getY() - a.getY());
  Point ct0(c.getX() - a.getX(), c.getY() - a.getY());
  Fixed AreaSize = getAriaSize(bt0.getX(), ct0.getY(), ct0.getX(), bt0.getY());
  if (AreaSize == Fixed(0))
    return (false);
  // translate()
  Point at(a.getX() - p.getX(), a.getY() - p.getY());
  Point bt(b.getX() - p.getX(), b.getY() - p.getY());
  Point ct(c.getX() - p.getX(), c.getY() - p.getY());
  // Partial Arias
  Fixed ABP = getAriaSize(at.getX(), bt.getY(), bt.getX(), at.getY());
  Fixed BCP = getAriaSize(bt.getX(), ct.getY(), ct.getX(), bt.getY());
  Fixed CAP = getAriaSize(ct.getX(), at.getY(), at.getX(), ct.getY());
  if (ABP == Fixed(0) || BCP == Fixed(0) || CAP == Fixed(0))
    return (false);
  Fixed PartSum = ABP + BCP + CAP;
  if (PartSum == AreaSize)
    return (true);
  return (false);
  // solve about y=0;
  /*
    原点O（0,0）と、点P1(x1, y1),P2(y1,y2)による三角形の面積Sは、
    S = (1/2) * (x1*y2 - x2*y1);
    または、
    S = (1/2) * (x2*y1 - x1 * y2);
    で求められる。
    参考：https://ouchimath.com/3point-menseki/
  */
}
