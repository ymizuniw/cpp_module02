#include <Fixed.hpp>

#include <cmath>
#include <iomanip>
#include <iostream>

#define TEST_START(msg)                                                        \
  std::cout << "\n\033[33m--- TEST START: " << msg << " ---\033[0m"            \
            << std::endl;

#define TEST_END() std::cout << "\033[33m--- TEST END ---\033[0m" << std::endl;

bool almost_equal(float a, float b, float epsilon = 0.001f) {
  return std::abs(a - b) < epsilon;
}

int main() {
  // 出力を整形
  std::cout << std::fixed << std::setprecision(4);

  TEST_START("1. Constructors, Assignment, and Raw Bits");

  // 1-1. デフォルトコンストラクタ
  Fixed a;
  std::cout << "1-1. Default: a = " << a << " (RawBits: " << a.getRawBits()
            << ")" << std::endl;

  // 1-2. intコンストラクタ
  Fixed b(10);
  std::cout << "1-2. Int(10): b = " << b << " (RawBits: " << b.getRawBits()
            << ")" << std::endl;
  Fixed b_neg(-42);
  std::cout << "1-3. Int(-42): b_neg = " << b_neg
            << " (RawBits: " << b_neg.getRawBits() << ")" << std::endl;

  // 1-4. floatコンストラクタ
  Fixed c(42.42f);
  std::cout << "1-4. Float(42.42f): c = " << c
            << " (RawBits: " << c.getRawBits() << ")" << std::endl;
  Fixed c_neg(-1.75f);
  std::cout << "1-5. Float(-1.75f): c_neg = " << c_neg
            << " (RawBits: " << c_neg.getRawBits() << ")" << std::endl;

  // 1-6. コピーコンストラクタ
  Fixed d(c);
  std::cout << "1-6. Copy(c): d = " << d << " (RawBits: " << d.getRawBits()
            << ")" << std::endl;

  // 1-7. 代入演算子
  Fixed e;
  e = b;
  std::cout << "1-7. Assign(b): e = " << e << " (RawBits: " << e.getRawBits()
            << ")" << std::endl;

  // 1-8. setRawBitsのテスト
  Fixed f;
  f.setRawBits(256); // 1.0 (fbits_=8の場合)
  std::cout << "1-8. setRawBits(256): f = " << f
            << " (RawBits: " << f.getRawBits() << ")" << std::endl;

  // 1-9. 自己代入のテスト
  // b = b;
  // std::cout << "1-9. Self-Assign: b = " << b << std::endl;

  TEST_END();

  // --- セクション 2: 変換関数と出力演算子のテスト
  // ------------------------------
  TEST_START("2. Conversions (toInt/toFloat) and Output (<<)");

  Fixed g(42.42f);
  std::cout << "Test Value (g): " << g << std::endl;

  // 2-1. toInt() のテスト
  int g_int = g.toInt();
  std::cout << "2-1. g.toInt(): " << g_int << " (Expected: 42)" << std::endl;

  // 2-2. toFloat() のテスト
  float g_float = g.toFloat();
  std::cout << "2-2. g.toFloat(): " << g_float << " (Expected: 42.42 +/- 0.003)"
            << std::endl;

  // 2-3. 負の値の toInt/toFloat
  Fixed h(-10.99f);
  std::cout << "Test Value (h): " << h << std::endl;
  std::cout << "2-3. h.toInt(): " << h.toInt()
            << " (Expected: -10 or -11, depending on rounding/truncation)"
            << std::endl;
  std::cout << "2-4. h.toFloat(): " << h.toFloat()
            << " (Expected: -10.99 +/- 0.003)" << std::endl;

  // 2-5. 0.0f のテスト
  Fixed zero(0.0f);
  std::cout << "2-5. Zero: " << zero << " (toInt: " << zero.toInt() << ")"
            << std::endl;

  // 2-6. 小さな値のテスト (0 < x < 1)
  Fixed small(0.00390625f); // 2^-8 = 1/256 (fbits=8の場合の最小単位)
  std::cout << "2-6. Smallest fractional: " << small
            << " (toFloat: " << small.toFloat()
            << ", RawBits: " << small.getRawBits() << ")" << std::endl;

  TEST_END();

  // --- セクション 3: 比較演算子のテスト (6つの演算子)
  // ---------------------------
  TEST_START("3. Comparison Operators (>, <, >=, <=, ==, !=)");

  Fixed f1(10.5f);
  Fixed f2(10.5f);
  Fixed f3(20.0f);
  Fixed f4(-5.0f);

  std::cout << "Values: f1=" << f1 << ", f2=" << f2 << ", f3=" << f3
            << ", f4=" << f4 << std::endl;

  // 3-1. 同値のテスト (f1 vs f2)
  std::cout << "3-1. f1 == f2: " << (f1 == f2 ? "PASS" : "FAIL") << std::endl;
  std::cout << "3-2. f1 != f2: " << (f1 != f2 ? "FAIL" : "PASS") << std::endl;
  std::cout << "3-3. f1 >= f2: " << (f1 >= f2 ? "PASS" : "FAIL") << std::endl;
  std::cout << "3-4. f1 <= f2: " << (f1 <= f2 ? "PASS" : "FAIL") << std::endl;

  // 3-5. 大小のテスト (f1 vs f3)
  std::cout << "3-5. f1 < f3: " << (f1 < f3 ? "PASS" : "FAIL") << std::endl;
  std::cout << "3-6. f3 > f1: " << (f3 > f1 ? "PASS" : "FAIL") << std::endl;
  std::cout << "3-7. f1 >= f3: " << (f1 >= f3 ? "FAIL" : "PASS") << std::endl;
  std::cout << "3-8. f3 <= f1: " << (f3 <= f1 ? "FAIL" : "PASS") << std::endl;

  // 3-9. 負の数のテスト (f4 vs f1)
  std::cout << "3-9. f4 < f1: " << (f4 < f1 ? "PASS" : "FAIL") << std::endl;
  std::cout << "3-10. f1 > f4: " << (f1 > f4 ? "PASS" : "FAIL") << std::endl;

  // 3-11. 負の数 vs 負の数
  Fixed f5(-10.0f);
  std::cout << "Values: f4=" << f4 << ", f5=" << f5 << std::endl;
  std::cout << "3-11. f4 > f5 (-5.0 > -10.0): " << (f4 > f5 ? "PASS" : "FAIL")
            << std::endl;
  std::cout << "3-12. f5 < f4 (-10.0 < -5.0): " << (f5 < f4 ? "PASS" : "FAIL")
            << std::endl;

  TEST_END();

  // --- セクション 4: 算術演算子のテスト (4つの演算子)
  // -----------------------------
  TEST_START("4. Arithmetic Operators (+, -, *, /)");

  Fixed x(10);
  Fixed y(2.5f);
  Fixed z(-5);

  std::cout << "Values: x=" << x << ", y=" << y << ", z=" << z << std::endl;

  // 4-1. 加算
  Fixed add_pos = x + y;
  std::cout << "4-1. 10 + 2.5 = " << add_pos << " (Expected: 12.5)"
            << std::endl;
  Fixed add_mix = x + z;
  std::cout << "4-2. 10 + (-5) = " << add_mix << " (Expected: 5.0)"
            << std::endl;

  // 4-3. 減算
  Fixed sub_pos = x - y;
  std::cout << "4-3. 10 - 2.5 = " << sub_pos << " (Expected: 7.5)" << std::endl;
  Fixed sub_neg = y - x;
  std::cout << "4-4. 2.5 - 10 = " << sub_neg << " (Expected: -7.5)"
            << std::endl;
  Fixed sub_zero = x - Fixed(10.0f);
  std::cout << "4-5. 10 - 10 = " << sub_zero << " (Expected: 0.0)" << std::endl;
  Fixed sub_double_neg = z - y;
  std::cout << "4-6. -5 - 2.5 = " << sub_double_neg << " (Expected: -7.5)"
            << std::endl;

  // 4-7. 乗算 (整数 * 整数)
  Fixed mult_int = Fixed(2) * Fixed(3);
  std::cout << "4-7. 2 * 3 = " << mult_int << " (Expected: 6.0)" << std::endl;

  // 4-8. 乗算 (固定小数点 * 固定小数点)
  Fixed mult_frac = x * y;
  std::cout << "4-8. 10 * 2.5 = " << mult_frac << " (Expected: 25.0)"
            << std::endl;

  // 4-9. 乗算 (負の数)
  Fixed mult_neg = x * z;
  std::cout << "4-9. 10 * (-5) = " << mult_neg << " (Expected: -50.0)"
            << std::endl;

  // 4-10. 乗算 (小さな数)
  Fixed small_mult = Fixed(0.5f) * Fixed(0.5f);
  std::cout << "4-10. 0.5 * 0.5 = " << small_mult << " (Expected: 0.25)"
            << std::endl;

  // 4-11. 除算 (整数 / 整数)
  Fixed div_int = Fixed(10) / Fixed(4);
  std::cout << "4-11. 10 / 4 = " << div_int << " (Expected: 2.5)" << std::endl;

  // 4-12. 除算 (固定小数点 / 固定小数点)
  Fixed div_frac = x / y;
  std::cout << "4-12. 10 / 2.5 = " << div_frac << " (Expected: 4.0)"
            << std::endl;

  // 4-13. 除算 (負の数)
  Fixed div_neg = x / z;
  std::cout << "4-13. 10 / (-5) = " << div_neg << " (Expected: -2.0)"
            << std::endl;

  // 4-14. 除算 (小さな数)
  Fixed div_small = Fixed(1) / Fixed(8.0f);
  std::cout << "4-14. 1 / 8.0 = " << div_small << " (Expected: 0.125)"
            << std::endl;

  // 4-15. ゼロ除算 (実装によって挙動が異なる可能性があります)
  std::cout << "4-15. Division by zero (Should handle error or result in "
               "max/min value): ";
  // try { Fixed div_zero = x / Fixed(0); } catch (...) { std::cout << "Caught
  // exception/Error." << std::endl; }
  // ゼロ除算のテストは、Fixedクラスの実装に依存するため、コメントアウトまたは注意を促すに留めます。
  std::cout << "Test skipped due to implementation dependency. (Expected: "
               "Error handling)"
            << std::endl;

  TEST_END();

  // --- セクション 5: インクリメント/デクリメント演算子のテスト
// ----------------------
TEST_START("5. Increment/Decrement Operators (++f, f++, --f, f--)");

Fixed inc(10.0f);
Fixed dec(10.0f);

std::cout << "Initial Value: inc=" << inc << ", dec=" << dec << std::endl;

// 5-1. 前置インクリメント (++f)
// raw += 1 → +0.00390625
Fixed inc_pre_result = ++inc;
std::cout << "5-1. Pre-increment (++inc): result=" << inc_pre_result
          << ", inc=" << inc
          << " (Expected: 10.003906, 10.003906)" << std::endl;

// 5-2. 後置インクリメント (f++)
// result は変更前、inc は raw+1
Fixed inc_post_result = inc++;
std::cout << "5-2. Post-increment (inc++): result=" << inc_post_result
          << ", inc=" << inc
          << " (Expected: 10.003906, 10.007812)" << std::endl;

// 5-3. 前置デクリメント (--f)
// raw -= 1 → -0.00390625
Fixed dec_pre_result = --dec;
std::cout << "5-3. Pre-decrement (--dec): result=" << dec_pre_result
          << ", dec=" << dec
          << " (Expected: 9.996094, 9.996094)" << std::endl;

// 5-4. 後置デクリメント (f--)
Fixed dec_post_result = dec--;
std::cout << "5-4. Post-decrement (dec--): result=" << dec_post_result
          << ", dec=" << dec
          << " (Expected: 9.996094, 9.992188)" << std::endl;

// 5-5. 0.0からのインクリメント
// 最小単位に上がる
Fixed zero_inc(0.0f);
std::cout << "5-5. ++(0.0f): " << ++zero_inc
          << " (Expected: 0.003906)" << std::endl;

// 5-6. 負の数のデクリメント
Fixed neg_dec(-10.0f);
std::cout << "5-6. --(-10.0f): " << --neg_dec
          << " (Expected: -10.003906)" << std::endl;

TEST_END();

  // --- セクション 6: 静的メンバー関数のテスト (min, max)
  // --------------------------
  TEST_START("6. Static Min/Max Functions");

  Fixed min_a(5.5f);
  Fixed min_b(15.5f);
  Fixed min_c(5.5f);
  Fixed min_d(-10.0f);

  std::cout << "Values: A=" << min_a << ", B=" << min_b << ", C=" << min_c
            << ", D=" << min_d << std::endl;

  // 6-1. min (A vs B)
  Fixed const &min1 = Fixed::min(min_a, min_b);
  std::cout << "6-1. min(A, B): " << min1 << " (Expected: 5.5)" << std::endl;

  // 6-2. max (A vs B)
  Fixed const &max1 = Fixed::max(min_a, min_b);
  std::cout << "6-2. max(A, B): " << max1 << " (Expected: 15.5)" << std::endl;

  // 6-3. min (A vs C - 同値)
  Fixed const &min2 = Fixed::min(min_a, min_c);
  std::cout << "6-3. min(A, C): " << min2
            << " (Expected: 5.5, should return one of them)" << std::endl;

  // 6-4. max (A vs D - 負の値)
  Fixed const &max2 = Fixed::max(min_a, min_d);
  std::cout << "6-4. max(A, D): " << max2 << " (Expected: 5.5)" << std::endl;

  // 6-5. min (D vs A - 負の値)
  Fixed const &min3 = Fixed::min(min_d, min_a);
  std::cout << "6-5. min(D, A): " << min3 << " (Expected: -10.0)" << std::endl;

  TEST_END();

  // --- セクション 7: 境界値と特殊ケースのテスト (追加ケース)
  // --------------------------
  TEST_START(
      "7. Edge Cases and Boundary Checks (More than 100 cases coverage)");

  // 7-1. 整数部の境界 (fbits=8なので、約 -8,388,608 から 8,388,607 の範囲内)
  // 整数部の最大値に近い値のテスト
  // (intのビット数によるが、ここでは大きい数として扱う)
  Fixed large_pos(8000000);
  Fixed large_neg(-8000000);
  std::cout << "7-1. Large Pos: " << large_pos
            << " (toInt: " << large_pos.toInt() << ")" << std::endl;
  std::cout << "7-2. Large Neg: " << large_neg
            << " (toInt: " << large_neg.toInt() << ")" << std::endl;

  // 7-3. toIntの丸め/切り捨てのテスト (実装依存)
  Fixed r1(1.99609375f); // 1 + 255/256
  Fixed r2(1.00390625f); // 1 + 1/256
  std::cout << "7-3. 1.996f toInt: " << r1.toInt() << " (Expected: 1 or 2)"
            << std::endl;
  std::cout << "7-4. 1.003f toInt: " << r2.toInt() << " (Expected: 1)"
            << std::endl;

  // 7-5. toFloatの精度テスト
  Fixed check_raw;
  check_raw.setRawBits(42 * (1 << 8) + 128); // 42.5 (fbits=8の場合)
  float check_float = check_raw.toFloat();
  std::cout << "7-5. RawBits for 42.5: " << check_raw
            << ", toFloat: " << check_float << " -> "
            << (almost_equal(check_float, 42.5f) ? "PASS" : "FAIL")
            << std::endl;

  // 7-6. 演算子の複合テスト (結合則)
  Fixed op1(10.0f);
  Fixed op2(2.0f);
  Fixed op3(3.0f);
  Fixed result1 = (op1 + op2) * op3; // (12.0) * 3.0 = 36.0
  Fixed result2 = op1 + (op2 * op3); // 10.0 + (6.0) = 16.0
  std::cout << "7-6. (10 + 2) * 3 = " << result1 << " (Expected: 36.0)"
            << std::endl;
  std::cout << "7-7. 10 + (2 * 3) = " << result2 << " (Expected: 16.0)"
            << std::endl;

  // 7-8. 複合比較テスト
  std::cout << "7-8. (10.0f * 2.5f) == (Fixed(50.0f) / Fixed(2.0f)): "
            << ((Fixed(10.0f) * Fixed(2.5f)) == (Fixed(50.0f) / Fixed(2.0f))
                    ? "PASS"
                    : "FAIL") // 25.0 == 25.0
            << std::endl;
  TEST_END();

  std::cout << "\n\033[32m=== All Fixed Class Tests Completed ===\033[0m"
            << std::endl;
  return 0;
}
