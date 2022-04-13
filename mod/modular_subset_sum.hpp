#include "alg/monoid_rollinghash.hpp"
#include "other/random.hpp"
#include "ds/segtree.hpp"

/*
(|vals| + mod) * log^2(mod)
verify: https://codeforces.com/gym/103428/problem/C
・vc<bool>：作れたかどうか
・vc<int>：最後に使った idx
*/
pair<vc<bool>, vc<int>> modular_subset_sum(int mod, vc<int> vals) {
  using Mono = Monoid_Rolling_Hash;
  RandomNumberGenerator RNG;
  const ll base = RNG(0, (1LL << 61) - 1);
  vc<pair<modint61, modint61>> seg_raw(mod + mod);
  FOR(i, mod + mod) seg_raw[i] = {base, 0};
  SegTree<Mono> seg(seg_raw);

  vc<bool> can(mod);
  vc<int> idx(mod, -1);

  auto add = [&](int x, int i) -> void {
    can[x] = 1;
    idx[x] = i;
    seg.set(x, {base, 1});
    seg.set(x + mod, {base, 1});
  };

  add(0, -1);

  FOR(i, len(vals)) {
    ll val = vals[i];
    val %= mod;
    vc<pi> LR;
    LR.eb(0, mod);
    vc<int> ADD;
    while (len(LR)) {
      auto [L, R] = LR.back();
      LR.pop_back();
      if (L == R) continue;
      modint61 x1 = seg.prod(L, R).se;
      modint61 x2 = seg.prod(mod + L - val, mod + R - val).se;
      if (x1 == x2) continue;
      if (R == L + 1) {
        // 対称差 L が見つかった
        if (!can[L]) ADD.eb(L);
        continue;
      }
      ll M = (L + R) / 2;
      LR.eb(L, M);
      LR.eb(M, R);
    }
    for (auto&& a: ADD) add(a, i);
  }

  return {can, idx};
}