#include "geo/base.hpp"
#include "geo/convexhull.hpp"

template <typename T = ll>
struct CHT_xy {
  /*
  いろんな (a, b) を入れる → ax+by の min, max を検索する
  */
  using P = Point<T>;
  vc<P> points;
  bool is_prepared = 0;

  void add(P p) {
    assert(!is_prepared);
    points.eb(p);
  }

  void add(T a, T b) { add(Point(a, b)); }

  template <typename A, typename B>
  void add(pair<A, B> p) {
    add(Point(p));
  }

  int size() { return len(points); }

  void build() {
    assert(!is_prepared);
    is_prepared = 1;
    vc<P> tmp;
    auto I = ConvexHull(points);
    for (auto&& i: I) tmp.eb(points[i]);
    points = tmp;
  }

  T eval_at(T x, T y, int n) {
    n %= points.size();
    auto& p = points[n];
    return p.x * x + p.y * y;
  }

  template <typename F>
  T minimize(int n, F f) {
    // 「狭義単調増加 → 狭義単調減少」な周期 n の関数の最小化
    int a = 0, b = n, c = 2 * n;
    while (c - a > 2) {
      int l = (a + b) / 2, r = (b + c + 1) / 2;
      if (f(l) < f(b)) tie(c, b) = mp(b, l);
      elif (f(b) > f(r)) tie(a, b) = mp(b, r);
      else tie(a, c) = mp(l, r);
    }
    return f(b);
  }

  T get_min(T x, T y) {
    assert(is_prepared && size());
    auto f = [&](ll n) -> T { return eval_at(x, y, n); };
    return minimize(size(), f);
  }

  T get_max(T x, T y) {
    assert(is_prepared && size());
    auto f = [&](ll n) -> T { return -eval_at(x, y, n); };
    return -minimize(size(), f);
  }
};
