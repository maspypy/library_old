#include "ds/lazysegtree.hpp"
#include "graph/hld.hpp"
#include "algebra/reverselazy.hpp"

template <typename HLD, typename Lazy, bool edge = false>
struct LazyTreeMonoid {
  using MonoX = typename Lazy::X_structure;
  using MonoA = typename Lazy::A_structure;
  using X = typename MonoX::value_type;
  using A = typename MonoA::value_type;
  using RevLazy = Lazy_Reverse<Lazy>;
  HLD &hld;
  int N;
  LazySegTree<Lazy> seg;
  LazySegTree<RevLazy> seg_r;

  LazyTreeMonoid(HLD &hld) : hld(hld), N(hld.N), seg(hld.N) {
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(hld.N);
  }

  LazyTreeMonoid(HLD &hld, vc<X> &dat) : hld(hld), N(hld.N) {
    vc<X> seg_raw(N, MonoX::unit);
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(e, N - 1) {
        int v = hld.e_to_v(e);
        seg_raw[hld.LID[v]] = dat[e];
      }
    }
    seg = LazySegTree<Lazy>(seg_raw);
    if (!MonoX::commute) seg_r = LazySegTree<RevLazy>(seg_raw);
  }

  void set(int i, X x) {
    if (edge) i = hld.e_to_v(i);
    i = hld.LID[i];
    seg.set(i, x);
    if (!MonoX::commute) seg_r.set(i, x);
  }

  X prod_path_nc(int u, int v) {
    X xl = MonoX::unit, xr = MonoX::unit;
    while (1) {
      if (hld.head[u] == hld.head[v]) break;
      if (hld.LID[u] < hld.LID[v]) {
        xr = MonoX::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), xr);
        v = hld.parent[hld.head[v]];
      } else {
        xl = MonoX::op(xl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));
        u = hld.parent[hld.head[u]];
      }
    }
    X xm = (hld.LID[u] < hld.LID[v]
                ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)
                : seg_r.prod(hld.LID[v] + edge, hld.LID[u] + 1));
    return MonoX::op(xl, MonoX::op(xm, xr));
  }

  X prod_path(int u, int v) {
    if (!MonoX::commute) return prod_path_nc(u, v);
    X val = MonoX::unit;
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      val = MonoX::op(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), val);
      v = hld.parent[hld.head[v]];
    }
    return MonoX::op(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);
  }

  X prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  void apply_path(int u, int v, A a) {
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      seg.apply(hld.LID[hld.head[v]], hld.LID[v] + 1, a);
      v = hld.parent[hld.head[v]];
    }
    seg.apply(hld.LID[u] + edge, hld.LID[v] + 1, a);
  }

  void apply_subtree(int u, A a) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.apply(l + edge, r, a);
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
