#include "polynomial/fps_inv.hpp"

template <typename mint>
vc<mint> fps_log(vc<mint>& f) {
  ll N = len(f);
  vc<mint> df = f;
  FOR(i, N) df[i] *= mint(i);
  df.erase(df.begin());
  auto f_inv = fps_inv(f);
  f = convolution(df, f_inv);
  f.resize(N - 1);
  f.insert(f.begin(), 0);
  FOR(i, N) f[i] *= inv<mint>(i);
  return f;
}
