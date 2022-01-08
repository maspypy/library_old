#include "polynomial/fps_inv.hpp"

template <typename mint>
vc<mint> mid_prod(vc<mint>& a, vc<mint>& b) {
  assert(len(a) >= len(b) && !b.empty());
  if (min(len(b), len(a) - len(b) + 1) <= 60) {
    vc<mint> res(len(a) - len(b) + 1);
    FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];
    return res;
  }
  int n = 1 << std::__lg(2 * len(a) - 1);
  vc<mint> fa(n), fb(n);
  std::copy(a.begin(), a.end(), fa.begin());
  std::copy(b.rbegin(), b.rend(), fb.begin());
  ntt(fa, 0), ntt(fb, 0);
  FOR(i, n) fa[i] *= fb[i];
  ntt(fa, 1);
  fa.resize(len(a));
  fa.erase(fa.begin(), fa.begin() + len(b) - 1);
  return fa;
}

template <typename mint>
vc<mint> multipoint_eval(vc<mint>& f, vc<mint>& x) {
  int n = len(f), m = len(x);
  int sz = 1;
  while (sz < m) sz *= 2;
  vc<vc<mint>> T(2 * sz);
  FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};
  FOR3_R(i, 1, sz) T[i] = convolution(T[2 * i], T[2 * i + 1]);
  f.resize(2 * n - 1);
  T[1].resize(n);
  T[1] = fps_inv(T[1]);
  T[1] = mid_prod(f, T[1]);
  T[1].resize(sz);

  FOR3(i, 1, sz) {
    T[2 * i] = mid_prod(T[i], T[2 * i]);
    T[2 * i + 1] = mid_prod(T[i], T[2 * i + 1]);
    swap(T[2 * i], T[2 * i + 1]);
  }
  vc<mint> vals(m);
  FOR(i, m) vals[i] = (len(T[sz + i]) ? T[sz + i][0] : 0);
  return vals;
}
