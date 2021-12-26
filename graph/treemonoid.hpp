#include "ds/segtree.hpp"
#include "graph/hld.hpp"

template <typename Graph, typename E, bool edge = false>
struct TreeMonoid {
  using F = function<E(E, E)>;
  HLD<Graph> &hld;
  int N;
  F f;
  E unit;
  bool commute;
  SegTree<E> seg, seg_r;

  TreeMonoid(HLD<Graph> &hld, Monoid<E> Mono)
      : hld(hld)
      , N(hld.N)
      , f(Mono.f)
      , unit(Mono.unit)
      , commute(Mono.commute)
      , seg(Mono)
      , seg_r(Monoid_reverse<E>(Mono)) {
    seg.init(N);
    if (!commute) seg_r.init(N);
  };

  void init(vc<E> &dat) {
    // vertex index OR edge index
    vc<E> seg_raw(N, unit);
    if (!edge) {
      FOR(v, N) seg_raw[hld.LID[v]] = dat[v];
    } else {
      FOR(i, N - 1) {
        int v = hld.e_to_v[i];
        seg_raw[hld.LID[v]] = dat[i];
      }
    }
    seg.build(seg_raw);
    if (!commute) seg_r.build(seg_raw);
  }

  void set(int i, E x) {
    if (edge) i = hld.e_to_v[i];
    i = hld.LID[i];
    seg.set(i, x);
    if (!commute) seg_r.set(i, x);
  }

  E prod_path_nc(int u, int v) {
    E vl = unit, vr = unit;
    while (1) {
      if (hld.head[u] == hld.head[v]) break;
      if (hld.LID[u] < hld.LID[v]) {
        vr = f(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);
        v = hld.parent[hld.head[v]];
      } else {
        vl = f(vl, seg_r.prod(hld.LID[hld.head[u]], hld.LID[u] + 1));
        u = hld.parent[hld.head[u]];
      }
    }
    E vm =
      (hld.LID[u] < hld.LID[v] ? seg.prod(hld.LID[u] + edge, hld.LID[v] + 1)
                               : seg_r.prod(hld.LID[v] + edge, hld.LID[u] + 1));
    return f(vl, f(vm, vr));
  }

  E prod_path(int u, int v) {
    if (!commute) return prod_path_nc(u, v);
    E val = unit;
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      val = f(seg.prod(hld.LID[hld.head[v]], hld.LID[v] + 1), val);
      v = hld.parent[hld.head[v]];
    }
    return f(seg.prod(hld.LID[u] + edge, hld.LID[v] + 1), val);
  }

  E prod_subtree(int u) {
    int l = hld.LID[u], r = hld.RID[u];
    return seg.prod(l + edge, r);
  }

  void debug() {
    print("hld");
    hld.debug();
    print("seg");
    seg.debug();
    print("seg_r");
    seg_r.debug();
  }

  void doc() {
    print("HL分解 + セグ木。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(log^2N) 時間。");
    print("関連");
  }
};
