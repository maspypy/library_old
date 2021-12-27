#include "algebra/monoid.hpp"

template <typename E, bool SMALL = false>
struct SegTree2D {
  using F = function<E(E, E)>;
  E unit;
  F f;
  int N;
  int full_N;
  vi keyX;
  int min_X;
  vc<int> indptr;
  vi keyY;
  vc<E> dat;

  SegTree2D(Monoid<E> Mono, vi& X, vi& Y, vc<E>& wt) : f(Mono.f), unit(Mono.unit) {
    assert(Mono.commute); // 可換モノイドのみ
    build(X, Y, wt);
  }

  SegTree2D(Monoid<E> Mono, vi& X, vi& Y) : f(Mono.f), unit(Mono.unit) {
    assert(Mono.commute); // 可換モノイドのみ
    vc<E> wt(len(X), unit);
    build(X, Y, wt);
  }

  inline int xtoi(int x) { return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x)); }

  void build(vi& X, vi& Y, vc<E>& wt) {
    if (!SMALL) {
      keyX = X;
      UNIQUE(keyX);
      N = len(keyX);
    } else {
      min_X = (len(X) == 0 ? 0 : MIN(X));
      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;
      keyX.resize(N);
      FOR(i, N) keyX[i] = min_X + i;
    }

    vc<vi> keyY_raw(N + N);
    vc<vc<E>> dat_raw(N + N);

    auto I = argsort(Y);
    for (auto&& i: I) {
      int ix = xtoi(X[i]), y = Y[i];
      ix += N;
      while (ix) {
        auto& KY = keyY_raw[ix];
        if (len(KY) == 0 || KY.back() < y) {
          KY.eb(y);
          dat_raw[ix].eb(wt[i]);
        } else {
          dat_raw[ix].back() = f(dat_raw[ix].back(), wt[i]);
        }
        ix >>= 1;
      }
    }

    indptr.assign(N + N + 1, 0);
    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);
    int full_N = indptr.back();
    keyY.resize(full_N);
    dat.assign(2 * full_N, unit);
    FOR(i, N + N) {
      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];
      FOR(j, n) {
        keyY[indptr[i] + j] = keyY_raw[i][j];
        dat[off + n + j] = dat_raw[i][j];
      }
      FOR3_R(j, 1, n)
      dat[off + j] = f(dat[off + 2 * j + 0], dat[off + 2 * j + 1]);
    }
  }

  void multiply_i(int i, ll y, E val) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    assert(keyY[LID + j] == y);
    int off = 2 * LID;
    j += n;

    while (j) {
      dat[off + j] = f(dat[off + j], val);
      j >>= 1;
    }
  }

  void multiply(ll x, ll y, E val) {
    int i = xtoi(x);
    assert(keyX[i] == x);
    i += N;
    while (i) {
      multiply_i(i, y, val);
      i >>= 1;
    }
  }

  E prod_i(int i, ll ly, ll ry) {
    E ret = 0;
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it;
    int R = lower_bound(it, it + n, ry) - it;
    int off = 2 * LID;
    L += n;
    R += n;
    E val = unit;
    while (L < R) {
      if (L & 1) val = f(val, dat[off + (L++)]);
      if (R & 1) val = f(dat[off + (--R)], val);
      L >>= 1;
      R >>= 1;
    }
    return val;
  }

  E prod(ll lx, ll rx, ll ly, ll ry) {
    int L = xtoi(lx);
    int R = xtoi(rx);
    L += N;
    R += N;
    E val = unit;
    while (L < R) {
      if (L & 1) val = f(val, prod_i(L++, ly, ry));
      if (R & 1) val = f(prod_i(--R, ly, ry), val);
      L >>= 1;
      R >>= 1;
    }
    return val;
  }

  void debug() {
    print("keyX", keyX);
    print("indptr", indptr);
    print("keyY", keyY);
    print("dat", dat);
  }
};