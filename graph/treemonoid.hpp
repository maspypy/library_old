#include "ds/segtree.hpp"

template <typename HLD, typename E, bool edge = false, bool commute = true>
struct TreeMonoid {
  using F = function<E(E, E)>;
  HLD &hld;
  int N;
  F seg_f;
  E E_unit;
  SegTree<E> seg, seg_r;

  TreeMonoid(HLD &hld, F seg_f, E E_unit)
      : hld(hld)
      , N(hld.N)
      , seg_f(seg_f)
      , E_unit(E_unit)
      , seg(seg_f, E_unit)
      , seg_r([&](E x, E y) -> E { return seg_f(y, x); }, E_unit) {
    seg.init(N);
    if (!commute) seg_r.init(N);
  };

  void init(vc<E> &dat) {
    // vertex index OR edge index
    vc<E> seg_raw(N, E_unit);
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

  E fold_path_nc(int u, int v) {
    E vl = E_unit, vr = E_unit;
    while (1) {
      if (hld.head[u] == hld.head[v]) break;
      if (hld.LID[u] < hld.LID[v]) {
        vr = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), vr);
        v = hld.parent[hld.head[v]];
      } else {
        vl = seg_f(vl, seg_r.fold(hld.LID[hld.head[u]], hld.LID[u] + 1));
        u = hld.parent[hld.head[u]];
      }
    }
    E vm =
      (hld.LID[u] < hld.LID[v] ? seg.fold(hld.LID[u] + edge, hld.LID[v] + 1)
                               : seg_r.fold(hld.LID[v] + edge, hld.LID[u] + 1));
    return seg_f(vl, seg_f(vm, vr));
  }

  E fold_path(int u, int v) {
    if (!commute) return fold_path_nc(u, v);
    E val = E_unit;
    while (1) {
      if (hld.LID[u] > hld.LID[v]) swap(u, v);
      if (hld.head[u] == hld.head[v]) break;
      val = seg_f(seg.fold(hld.LID[hld.head[v]], hld.LID[v] + 1), val);
      v = hld.parent[hld.head[v]];
    }
    return seg_f(seg.fold(hld.LID[u] + edge, hld.LID[v] + 1), val);
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
    print("パス順を気にする場合は、commute=falseとする。");
    print("関連");
    print("- 群ならパスクエリは TreeGrp で O(logN) 時間");
    print("- 変更なしならパスクエリは TreeMonoid_static で O(logN) 時間");
  }
};
