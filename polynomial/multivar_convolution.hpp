#include "polynomial/convolution.hpp"
template <typename mint>
vc<mint> multivar_convolution(vi ns, vc<mint>& f, vc<mint>& g) {
  /*
  (n0, n1, n2, ...) 進法での繰り上がりのない足し算に関する畳み込み

  example : ns = (2, 3) → 1 の位から順に 2, 3 進法
  [a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1), a(1,1), a(0,2), a(1,2)]
  [b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1), b(1,1), b(0,2), b(1,2)]
  c(0,2) = a(0,0)b(0,2) + a(0,1)b(0,1) + a(0,2)b(1,1)
  c4 = a0b4 + a2b2 + a4b0

  example : ns = (2, 2, ..., 2, 2)
  → subset convolution がこれの特殊ケース
  */
  int K = len(ns);
  int N = 1;
  FOR(k, K) N *= ns[k];
  assert(len(f) == N && len(g) == N);
  if (N == 1) return {f[0] * g[0]};

  auto chi = [&](ll i) -> ll {
    int x = 0;
    for (auto&& n : ns) {
      i /= n;
      x += i;
    }
    return x % K;
  };

  int sz = 1;
  while (sz < N + N) sz *= 2;
  vv(mint, ff, K, sz);
  vv(mint, gg, K, sz);

  FOR(i, N) {
    auto k = chi(i);
    ff[k][i] = f[i];
    gg[k][i] = g[i];
  }

  FOR(k, K) {
    ntt(ff[k], false);
    ntt(gg[k], false);
  }

  vv(mint, hh, K, sz);
  FOR(a, K) FOR(b, K) FOR(i, sz) { hh[(a + b) % K][i] += ff[a][i] * gg[b][i]; }
  FOR(k, K) ntt(hh[k], true);

  vc<mint> h(N);
  mint c = mint(1) / mint(sz);
  FOR(i, N) h[i] = hh[chi(i)][i] * c;
  return h;
}
