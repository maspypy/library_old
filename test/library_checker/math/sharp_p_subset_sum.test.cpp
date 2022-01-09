#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include "my_template.hpp"
#include "polynomial/fps_exp.hpp"

using mint = modint998;
void solve() {
  LL(N, T);
  VEC(ll, S, N);
  auto CNT = bin_count(S, T + 1);
  vc<mint> logf(T + 1);
  FOR3(x, 1, T + 1) {
    FOR3(d, 1, T / x + 1) {
      if (d & 1)
        logf[d * x] += mint(CNT[x]) * inv<mint>(d);
      else
        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);
    }
  }
  auto f = fps_exp(logf);
  f.erase(f.begin());
  print(f);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
