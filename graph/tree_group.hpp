#include "graph/hld.hpp"
#include "ds/algebra.hpp"

// 作ってみたものの、HLD(log^2N)より遅いがち？
template <typename Graph, typename E, bool edge = false>
struct TreeGroup {
  using F = function<E(E, E)>;
  using G = function<E(E)>;

  HLD<Graph> &hld;
  int N;
  F f;
  G inverse;
  E unit;
  const bool commute;
  const bool path_query;
  const bool subtree_query;
  SegTree<E> seg, seg_r, seg_subtree;

  TreeGroup(HLD<Graph> &hld, Monoid<E> Mono, bool path_query,
            bool subtree_query)
      : hld(hld)
      , N(hld.N)
      , f(Mono.f)
      , inverse(Mono.inverse)
      , unit(Mono.unit)
      , commute(Mono.commute)
      , path_query(path_query)
      , subtree_query(subtree_query)
      , seg(Mono)
      , seg_r(Monoid_reverse<E>(Mono))
      , seg_subtree(Mono) {
    assert(Mono.has_inverse);
    if (path_query) {
      seg.init(N + N);
      if (!commute) seg_r.init(N + N);
    }
    if (subtree_query) {
      assert(Mono.commute);
      seg_subtree.init(N);
    }
  };

  void init_path(vc<E> &dat) {
    vc<E> seg_raw(N + N, unit);
    if (!edge) {
      FOR(v, N) {
        seg_raw[hld.ELID[v]] = dat[v];
        seg_raw[hld.ERID[v]] = inverse(dat[v]);
      }
    } else {
      FOR(i, N - 1) {
        int v = hld.e_to_v[i];
        seg_raw[hld.ELID[v]] = dat[i];
        seg_raw[hld.ERID[v]] = inverse(dat[i]);
      }
    }
    seg.build(seg_raw);
    if (!commute) seg_r.build(seg_raw);
  }

  void init_subtree(vc<E> &dat) {
    vc<E> seg_raw(N, unit);
    if (!edge) {
      FOR(v, N) { seg_raw[hld.LID[v]] = dat[v]; }
    } else {
      FOR(i, N - 1) {
        int v = hld.e_to_v[i];
        seg_raw[hld.LID[v]] = dat[i];
      }
    }
    seg_subtree.build(seg_raw);
  }

  void init(vc<E> &dat) {
    // vertex index OR edge index
    if (path_query) init_path(dat);
    if (subtree_query) init_subtree(dat);
  }

  void set_path(int v, E x) {
    seg.set(hld.ELID[v], x);
    seg.set(hld.ERID[v], inverse(x));
    if (!commute) {
      seg_r.set(hld.ELID[v], x);
      seg_r.set(hld.ERID[v], inverse(x));
    }
  }

  void set_subtree(int v, E x) { seg_subtree.set(hld.LID[v], x); }

  void set(int i, E x) {
    int v = (edge ? hld.e_to_v[i] : i);
    if (path_query) set_path(v, x);
    if (subtree_query) set_subtree(v, x);
  }

  E prod_path(int frm, int to) {
    int lca = hld.LCA(frm, to);
    // [frm, lca)
    E x1 = (commute ? seg.prod(hld.ELID[lca] + 1, hld.ELID[frm] + 1)
                    : seg_r.prod(hld.ELID[lca] + 1, hld.ELID[frm] + 1));
    // edge なら (lca, to]、vertex なら [lca, to]
    E x2 = seg.prod(hld.ELID[lca] + edge, hld.ELID[to] + 1);
    return f(x1, x2);
  }

  E prod_subtree(int u) {
    assert(subtree_query);
    int l = hld.LID[u], r = hld.RID[u];
    return seg_subtree.prod(l + edge, r);
  }

  void debug() {
    print("hld");
    hld.debug();
    print("seg");
    seg.debug();
    print("seg_r");
    seg_r.debug();
    print("seg_subtree");
    seg_subtree.debug();
  }

  void doc() {
    print("EulerTour + セグ木。");
    print("逆元を利用して、パスクエリを O(logN) 時間で行う。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(logN) 時間。");
  }
};