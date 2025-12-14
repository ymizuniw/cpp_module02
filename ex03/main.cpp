#include <Point.hpp>
#include <cassert>
#include <cstring>
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const p);

int main(void) {
  Point a(0, 0);
  Point b(10, 0);
  Point c(0, 10);

  Point p1(2, 2);   // inside
  Point p2(10, 10); // outside
  Point p3(5, 0);   // on edge
  Point p4(0, 0);   // vertex
  Point p5(-1, 0);  // outside (extension)

  std::cout << bsp(a, b, c, p1) << std::endl; // 1
  std::cout << bsp(a, b, c, p2) << std::endl; // 0
  std::cout << bsp(a, b, c, p3) << std::endl; // 0
  std::cout << bsp(a, b, c, p4) << std::endl; // 0
  std::cout << bsp(a, b, c, p5) << std::endl; // 0

  // float test
  Point af(0.1f, 0.1f);
  Point bf(9.9f, 0.2f);
  Point cf(0.3f, 9.8f);

  Point pf1(1.0f, 1.0f); // inside
  Point pf2(0.0001f, 0.0001f);
  Point pf3(5.0f, 0.0000001f);

  std::cout << bsp(af, bf, cf, pf1) << std::endl; // 1
  std::cout << bsp(af, bf, cf, pf2) << std::endl; // 0
  std::cout << bsp(af, bf, cf, pf3) << std::endl; // 0

  Point ae(0, 0);
  Point be(1000000, 1);
  Point ce(0, 2);
  Point pe(1, 1);                                // inside
  std::cout << bsp(ae, be, ce, pe) << std::endl; // 1

  const float LSB = 1.0f / 256.0f;

  // --- inside, but very close to edge ---
  Point t1(LSB * 2, LSB * 2); // > 1 LSB inside
  Point t2(LSB * 1.1f, LSB * 1.1f);
  Point t3(LSB * 0.99f, LSB * 0.99f); // < 1 LSB (quantizes to 0)

  std::cout << bsp(a, b, c, t1) << std::endl; // expected: 1
  std::cout << bsp(a, b, c, t2) << std::endl; // expected: 1
  std::cout << bsp(a, b, c, t3) << std::endl; // expected: 0

  // --- near edge y=0 ---
  Point t4(5.0f, LSB * 2);    // clearly above edge
  Point t5(5.0f, LSB * 1.0f); // exactly 1 LSB
  Point t6(5.0f, LSB * 0.5f); // below threshold

  std::cout << bsp(a, b, c, t4) << std::endl; // expected: 1
  std::cout << bsp(a, b, c, t5) << std::endl; // expected: 1
  std::cout << bsp(a, b, c, t6) << std::endl; // expected: 0

  // --- corner threshold ---
  Point t7(LSB * 1.0f, 0.0f); // on edge after quantization
  Point t8(LSB * 2.0f, 0.0f); // still on edge geometrically

  std::cout << bsp(a, b, c, t7) << std::endl; // expected: 0
  std::cout << bsp(a, b, c, t8) << std::endl; // expected: 0
  return 0;
}
