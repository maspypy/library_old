#include "polynomial/fps_exp.hpp"
#include "polynomial/fps_log.hpp"

template <typename mint>
vc<mint> fps_pow(vc<mint>& f, ll k) {
  int n = len(f);
  int d = n;
  FOR_R(i, n) if (f[i] != 0) d = i;
  ll off = d * k;
  if (off >= n) return vc<mint>(n, 0);
  mint c = f[d];
  mint c_inv = mint(1) / mint(c);
  vc<mint> g(n - off);
  FOR(i, n - off) g[i] = f[d + i] * c_inv;
  auto log_g = fps_log(g);
  FOR(i, len(g)) log_g[i] *= mint(k);
  g = fps_exp(log_g);
  vc<mint> h(n);
  c = c.pow(k);
  FOR(i, len(g)) h[off + i] = g[i] * c;
  return h;
}
