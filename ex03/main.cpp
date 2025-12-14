#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

uint32_t as_bits(float x) {
  uint32_t u;
  std::memcpy(&u, &x, sizeof(float));
  return u;
}

int main(void) {
  float denormMin;
  float epsilon;
  float nextAfter0 = std::nextafterf(0.0f, 3.0f);
  float nextAfter1 = std::nextafterf(1.0f, 3.0f);
  //   float c;

  std::cout << std::setw(15) << std::left << "nextAfter0: " << nextAfter0
            << std::endl;
  std::cout << std::setw(15) << std::left << "nextAfter1: " << nextAfter1
            << std::endl;

  denormMin = std::numeric_limits<float>::denorm_min();
  epsilon = std::numeric_limits<float>::epsilon();

  float x1 = 1.0f;
  float y1 = x1 + denormMin;
  float y2 = x1 + epsilon;
  float y4 = x1 + 1.192010e-07;

  std::cout << std::setw(15) << std::left << "denormMin: " << denormMin
            << std::endl;
  std::cout << std::setw(15) << std::left << "epsilon: " << epsilon
            << std::endl;

  printf("x1 : %a\n", x1);
  printf("y1 : %a\n", y1);
  printf("y2 : %a\n", y2);
  printf("y4 : %a\n", y4);
  return (0);
}
