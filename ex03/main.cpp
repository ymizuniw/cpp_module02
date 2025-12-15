#include <Point.hpp>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const p);

static void print(int idx, bool expected, bool actual) {
  std::cout << "#" << (idx < 10 ? "0" : "") << idx << " " << expected << " "
            << actual << std::endl;
}

int main(void) {
  int i = 1;

  Point a(0, 0), b(10, 0), c(0, 10);

  print(i++, 1, bsp(a, b, c, Point(2, 2)));
  print(i++, 0, bsp(a, b, c, Point(10, 10)));
  print(i++, 0, bsp(a, b, c, Point(5, 0)));
  print(i++, 0, bsp(a, b, c, Point(0, 0)));
  print(i++, 0, bsp(a, b, c, Point(-1, 0)));

  Point af(0.1f, 0.1f), bf(9.9f, 0.2f), cf(0.3f, 9.8f);
  print(i++, 1, bsp(af, bf, cf, Point(1.0f, 1.0f)));
  print(i++, 0, bsp(af, bf, cf, Point(0.0001f, 0.0001f)));
  print(i++, 0, bsp(af, bf, cf, Point(5.0f, 0.0000001f)));

  print(i++, 1, bsp(Point(0, 0), Point(1000000, 1), Point(0, 2), Point(1, 1)));

  const float LSB = 1.0f / 256.0f;
  print(i++, 0, bsp(a, b, c, Point(LSB - (LSB - 0.00390624f), LSB))); // t1
  print(i++, 1, bsp(a, b, c, Point(LSB * 1.1f, LSB * 1.1f)));         // t2
  print(i++, 0, bsp(a, b, c, Point(LSB * 0.99f, LSB * 0.99f)));       // t3

  print(i++, 1, bsp(a, b, c, Point(5.0f, LSB * 2.0f)));
  print(i++, 1, bsp(a, b, c, Point(5.0f, LSB * 1.0f)));
  print(i++, 0, bsp(a, b, c, Point(5.0f, LSB * 0.5f)));

  print(i++, 0, bsp(a, b, c, Point(LSB * 1.0f, 0.0f)));
  print(i++, 0, bsp(a, b, c, Point(LSB * 2.0f, 0.0f)));

  return 0;
}
