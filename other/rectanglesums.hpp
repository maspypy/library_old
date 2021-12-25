#include "ds/fenwick.hpp"

template <typename WT = ll>
struct RectangleSums {
  int N;
  int n, Q;
  vi X, Y;
  vi keyX, keyY;
  vc<WT> wt;
  vc<vc<pair<int, WT>>> add;
  vc<vc<tuple<int, int, int>>> query_l;
  vc<vc<tuple<int, int, int>>> query_r;

  RectangleSums(int N)
      : N(N), n(0), Q(0), X(N), Y(N), keyX(N), keyY(N), wt(N) {}

  void add_pt(ll x, ll y, WT w = 1) {
    X[n] = x, Y[n] = y, wt[n] = w, keyX[n] = x, keyY[n] = y;
    ++n;
    if (n == N) { compress(); }
  }

  void compress() {
    UNIQUE(keyX), UNIQUE(keyY);
    add.resize(len(keyX) + 1);
    query_l.resize(len(keyX) + 1);
    query_r.resize(len(keyX) + 1);
    FOR(i, N) {
      ll x = X[i], y = Y[i], w = wt[i];
      x = LB(keyX, x), y = LB(keyY, y);
      add[x].eb(y, w);
    }
  }

  void add_rect(ll xl, ll xr, ll yl, ll yr) {
    assert(n == N);
    xl = LB(keyX, xl), xr = LB(keyX, xr);
    yl = LB(keyY, yl), yr = LB(keyY, yr);
    query_l[xl].eb(Q, yl, yr);
    query_r[xr].eb(Q, yl, yr);
    ++Q;
  };

  vc<WT> calc() {
    assert(n == N);
    vc<WT> ANS(Q);
    FenwickTree<WT> bit(len(keyY) + 1);
    FOR(x, len(keyX) + 1) {
      FORIN(t, query_l[x]) {
        auto [q, yl, yr] = t;
        ANS[q] -= bit.sum(yl, yr);
      }
      FORIN(t, query_r[x]) {
        auto [q, yl, yr] = t;
        ANS[q] += bit.sum(yl, yr);
      }
      FORIN(t, add[x]) {
        auto [y, w] = t;
        bit.add(y, w);
      }
    }
    return ANS;
  }
};
