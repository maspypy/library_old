#include "algebra/monoid.hpp"
#include "ds/fenwick.hpp"
#include "graph/hld.hpp"

template <typename Graph, typename E, bool edge = false>
struct TreeAbelGroup {
  HLD<Graph> &hld;
  int N;
  FenwickTree<E> bit_path, bit_subtree;
  bool path_sum, subtree_sum;

  TreeAbelGroup(HLD<Graph> &hld, bool path_sum, bool subtree_sum)
      : hld(hld), N(hld.N), path_sum(path_sum), subtree_sum(subtree_sum) {
    if (path_sum) bit_path.init(N + N);
    if (subtree_sum) bit_subtree.init(N);
  }

  void init_path(vc<E> &dat) {
    vc<E> fenwick_raw(N + N);
    if (!edge) {
      FOR(v, N) {
        fenwick_raw[hld.ELID[v]] = dat[v];
        fenwick_raw[hld.ERID[v]] = -dat[v];
      }
    } else {
      FOR(i, N - 1) {
        int v = hld.e_to_v[i];
        fenwick_raw[hld.ELID[v]] = dat[i];
        fenwick_raw[hld.ERID[v]] = -dat[i];
      }
    }
    bit_path.build(fenwick_raw);
  }

  void init_subtree(vc<E> &dat) {
    vc<E> fenwick_raw(N);
    if (!edge) {
      FOR(v, N) { fenwick_raw[hld.LID[v]] = dat[v]; }
    } else {
      FOR(i, N - 1) {
        int v = hld.e_to_v[i];
        fenwick_raw[hld.LID[v]] = dat[i];
      }
    }
    bit_subtree.build(fenwick_raw);
  }

  void init(vc<E> &dat) {
    // vertex index OR edge index
    if (path_sum) init_path(dat);
    if (subtree_sum) init_subtree(dat);
  }

  void add(int i, E x) {
    int v = (edge ? hld.e_to_v[i] : i);
    if (path_sum) {
      bit_path.add(hld.ELID[v], x);
      bit_path.add(hld.ERID[v], -x);
    }
    if (subtree_sum) { bit_subtree.add(hld.LID[v], x); }
  }

  E sum_path(int frm, int to) {
    int lca = hld.LCA(frm, to);
    E x1 = bit_path.sum(hld.ELID[lca] + 1, hld.ELID[frm] + 1);
    E x2 = bit_path.sum(hld.ELID[lca] + edge, hld.ELID[to] + 1);
    return x1 + x2;
  }

  E sum_subtree(int v) {
    return bit_subtree.sum(hld.LID[v] + edge, hld.RID[v]);
  }

  void debug() {
    print("hld");
    hld.debug();
    print("bit_path");
    bit_path.debug();
    print("bit_subtree");
    bit_subtree.debug();
  }

  void doc() {
    print("EulerTour + FenwickTree。");
    print("部分木クエリ O(logN) 時間、パスクエリ O(logN) 時間。");
    print("アーベル群であることを利用してパスクエリを O(logN) 時間にする。");
    print("operator +- が定義されている必要などがある");
  }
};
