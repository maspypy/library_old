// https://codeforces.com/contest/1436/problem/E

#include "ds/segtree.hpp"
#include "alg/monoid_min.hpp"
template <int BEGIN, typename T = ll>
struct RangeMexQuery {
  // 配列は static
  // クエリも先読みする
  vc<T>& A;
  vc<pair<int, int>> query;

  RangeMexQuery(vc<T>& A) : A(A) {}
  void add(int l, int r) { query.eb(l, r); }

  vc<T> calc() {
    int N = len(A);
    // segtree, value -> last idx
    using Mono = Monoid_Min<int, 1 << 30>;
    vc<int> seg_raw(N + 2, -1);
    SegTree<Mono> seg(seg_raw);

    int Q = len(query);
    vc<T> ANS(Q);
    vc<vc<int>> IDS(N + 1);
    FOR(q, Q) {
      auto [L, R] = query[q];
      IDS[R].eb(q);
    }

    FOR(i, N + 1) {
      // solve query
      for (auto&& q: IDS[i]) {
        auto [L, R] = query[q];
        auto check = [&](int x) -> bool { return x >= L; };
        int mex = seg.max_right(check, BEGIN);
        ANS[q] = mex;
      }
      // update segtree
      if (i < N && A[i] < N + 2) seg.set(A[i], i);
    }
    return ANS;
  }
};
