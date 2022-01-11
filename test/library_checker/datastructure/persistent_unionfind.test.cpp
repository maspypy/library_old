#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"
#include "my_template.hpp"

#include "pds/unionfind.hpp"

void solve() {
  LL(N, Q);

  PersistentUnionFind uf(N);
  using np = PersistentUnionFind::np;
  vc<np> UFS;

  UFS.reserve(Q + 1);
  UFS.eb(uf.init());

  FOR3(q, 1, Q + 1) {
    LL(t, k, u, v);
    ++k;
    if (t == 0) {
      UFS.eb(uf.merge(u, v, UFS[k]).se);
    } else {
      print(uf.same(u, v, UFS[k]));
      UFS.eb(UFS[q - 1]);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
