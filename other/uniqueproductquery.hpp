#include "ds/segtree.hpp"

// sample：https://codeforces.com/contest/703/problem/D
template <typename Mono>
struct UniqueProductQuery {
  /*
  [L, R) 内の要素を UNIQUE した上で、f(x) の総積をとったものを計算。
  クエリ先読みソート＋セグ木
  */
  using X = typename Mono::value_type;
  int N;
  vc<X> A;
  vc<pair<int, int>> query;

  UniqueProductQuery(vc<X> A) : N(len(A)), A(A) {}

  void add(int L, int R) {
    assert(0 <= L && L <= R && R <= N);
    query.eb(L, R);
  }

  template <typename F>
  vc<X> run(F f) {
    ll Q = len(query);
    vc<X> ANS(Q);
    vc<vc<int>> IDS(N + 1);
    FOR(q, Q) IDS[query[q].se].eb(q);
    SegTree<Mono> seg(N);

    unordered_map<X, int> pos;
    pos.reserve(N);

    FOR(i, N) {
      X x = A[i];
      if (pos.count(x)) seg.set(pos[x], Mono::unit);
      pos[x] = i;
      seg.set(i, f(A[i]));
      for (auto&& q: IDS[i + 1]) {
        auto [L, R] = query[q];
        ANS[q] = seg.prod(L, R);
      }
    }
    return ANS;
  }

  vc<X> run() {
    auto f = [&](X x) -> X { return x; };
    return run(f);
  }
};