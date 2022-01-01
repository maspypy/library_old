#include "ds/segtree.hpp"
#include "graph/hld.hpp"
#include "algebra/monoid_reverse.hpp"

template <typename HLD, typename Monoid, bool edge = false>
struct TreeMonoid {
  using RevMonoid = Monoid_Reverse<Monoid>;
  using X = typename Monoid::value_type;
  HLD &hld;
  int N;
  SegTree<Monoid> seg;
  SegTree<RevMonoid> seg_r;

  TreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {
    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(hld.N);
  }

  TreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {
    vc<X> seg_raw(N, Monoid::unit);
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = hld.e_to_v(e);
        seg_raw[hld.LID[v]] = dat[e];
      }
    }
    seg = SegTree<Monoid>(seg_raw);
    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);
  }

  void set(int i, X x) {
    if (edge) i = hld.e_to_v(i);
    i = hld.LID[i];
    seg.set(i, x);
    if (!Monoid::commute) seg_r.set(i, x);
  }

  X prod_path_nc(int u, int v) {
    X xl = Monoid::unit, xr = Monoid::unit;
    while (1) {
      if (hld.head[u] == hld.head[v]) break;
      if (hld.LID[u] < hld.LID[v]) {
        xr = Monoid::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), xr);
        v = hld.parent[hld.head[v]];
      } else {
        xl = Monoid::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));
        u = hld.parent[hld.head[u]];
      }
    }
    X xm = (hld.LID[u] < hld.LID[v]
                ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)
                : seg_r.prod(hld.LID[v] + edge, hld.LID[u] + 1));
    return Monoid::op(xl, Monoid::op(xm, xr));
  }

  X prod_path(int u, int v) {
    if (!Monoid::commute) return prod_path_nc(u, v);
    X val = Monoid::unit;
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      val = Monoid::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), val);
      v = hld.parent[hld.head[v]];
    }
    return Monoid::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  void debug() {
    print("tree_monoid");
    hld.debug();
    seg.debug();
    seg_r.debug();
  }

  void doc() {
    print("HL分解 + セグ木。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(log^2N) 時間。");
  }
};
