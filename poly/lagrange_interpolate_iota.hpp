#include "algebra/group_mul.hpp"
#include "ds/swag.hpp"
#include "poly/convolution.hpp"

template <typename mint>
vc<mint> lagrange_intepolate_iota(vc<mint> &f, mint c, int m) {
  /*
  Input: f(0), ..., f(n-1) and c, m (1 default)
  Return: f(c), f(c+1), ..., f(c+m-1)
  Complexity: M(n, m)
  */
  ll n = len(f);
  auto a = f;
  FOR(i, n) {
    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);
    if ((n - 1 - i) & 1) a[i] *= -1;
  }
  // x = c, c+1, ... に対して a0/x + a1/(x-1) + ... を求めておく
  vc<mint> b(n + m - 1);
  FOR(i, n + m - 1) b[i] = mint(1) / (c + mint(i - n + 1));
  a = convolution(a, b);

  SWAG<Group_Mul<mint>> swag;
  vc<mint> ANS(m);
  ll L = 0, R = 0;
  FOR(i, m) {
    while (L < i) { swag.pop(), ++L; }
    while (R - L < n) { swag.push(c + mint((R++) - n + 1)); }
    auto coef = swag.prod();
    if (coef == 0) {
      ANS[i] = f[(c + i).val];
    } else {
      ANS[i] = a[i + n - 1] * coef;
    }
  }
  return ANS;
}

template <typename mint>
mint lagrange_intepolate_iota(vc<mint> &f, mint c) {
  /*
  Input: f(0), ..., f(n-1) and c, m (1 default)
  Return: f(c)
  */
  return lagrange_interpolate_iota(f, c, 1)[0];
}
