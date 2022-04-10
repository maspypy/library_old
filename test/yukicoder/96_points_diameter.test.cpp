#define PROBLEM "https://yukicoder.me/problems/no/96"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"
#include "ds/unionfind.hpp"
#include "geo/points_diameter.hpp"

using P = Point<ll>;

void solve() {
  LL(N);
  if (N == 0) return print(1);
  vc<P> XY(N);
  FOR(i, N) {
    LL(x, y);
    XY[i] = {x, y};
  }

  HashMapLL<int> MP;
  auto to_key = [&](P p) -> ll { return p.x * 1e6 + p.y; };
  FOR(i, N) { MP[to_key(XY[i])] = i; }

  UnionFind uf(N);
  FOR(i, N) {
    P p = XY[i];
    FOR3(dx, 0, 11) FOR3(dy, -10, 11) {
      if (dx * dx + dy * dy > 100) continue;
      if (dx == 0 && dy == 0) continue;
      P q = p;
      q.x += dx, q.y += dy;
      ll key = to_key(q);
      if (!MP.count(key)) continue;
      ll j = MP[key];
      uf.merge(i, j);
    }
  }

  vc<vi> IDS(N);
  FOR(v, N) IDS[uf[v]].eb(v);

  using Re = double;
  Re ANS = 2.0;

  for (auto&& I: IDS) {
    if (len(I) == 0) continue;
    vc<P> xy;
    for (auto&& i: I) xy.eb(XY[i]);
    auto [a, b] = points_diameter(xy);
    P vec = xy[b] - xy[a];
    chmax(ANS, sqrt(Re(vec.dot(vec))) + 2.0);
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
