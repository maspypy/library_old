#include "alg/monoid_rollinghash.hpp"
#include "other/random.hpp"
#include "ds/segtree.hpp"

/*
(|vals| + mod) * log^2(mod)
verify: https://codeforces.com/gym/103428/problem/C
*/
vc<bool> modular_subset_sum(int mod, vc<int> vals) {
  using Mono = Monoid_Rolling_Hash;
  RandomNumberGenerator RNG;
  const ll base = RNG(0, (1LL << 61) - 1);
  vc<bool> A(mod + mod);
  ll cnt = 0;
  vc<pair<modint61, modint61>> seg_raw(mod + mod);
  FOR(i, mod + mod) seg_raw[i] = {base, 0};
  SegTree<Mono> seg(seg_raw);

  auto add = [&](ll x) -> void {
    ++cnt;
    A[x] = A[x + mod] = 1;
    seg.set(x, {base, 1});
    seg.set(x + mod, {base, 1});
  };

  add(0);

  for (auto&& val: vals) {
    val %= mod;
    if (cnt == mod) break;
    vc<pi> LR;
    LR.eb(0, mod);
    vi ADD;
    while (len(LR)) {
      auto [L, R] = LR.back();
      LR.pop_back();
      if (L == R) continue;
      modint61 x1 = seg.prod(L, R).se;
      modint61 x2 = seg.prod(mod + L - val, mod + R - val).se;
      if (x1 == x2) continue;
      if (R == L + 1) {
        // 対称差 L が見つかった
        if (!A[L]) ADD.eb(L);
        continue;
      }
      ll M = (L + R) / 2;
      LR.eb(L, M);
      LR.eb(M, R);
    }
    for (auto&& a: ADD) add(a);
  }

  A.resize(mod);
  return A;
}