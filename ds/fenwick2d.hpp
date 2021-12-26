template <typename T, bool SMALL=false>
struct Fenwick2D {
  int N;
  vi keyX;
  int min_X;
  vc<int> indptr;
  vi keyY;
  vc<T> dat;

  Fenwick2D(vi& X, vi& Y, vc<T>& wt) { build(X, Y, wt); }

  Fenwick2D(vi& X, vi& Y) {
    vc<T> wt(len(X), 0);
    build(X, Y, wt);
  }

  inline int xtoi(int x) {
    return (SMALL ? clamp(x - min_X, 0, N) : LB(keyX, x));
  }

  inline int nxt(int i) {
    i += 1;
    return i + (i & -i) - 1;
  }

  inline int prev(int i) {
    i += 1;
    return i - (i & -i) - 1;
  }

  void build(vi& X, vi& Y, vc<T>& wt) {
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

    vc<vi> keyY_raw(N);
    vc<vc<T>> dat_raw(N);

    auto I = argsort(Y);
    FORIN(i, I) {
      int ix = xtoi(X[i]), y = Y[i];
      while (ix < N) {
        auto& KY = keyY_raw[ix];
        if (len(KY) == 0 || KY.back() < y) {
          KY.eb(y);
          dat_raw[ix].eb(wt[i]);
        } else {
          dat_raw[ix].back() += wt[i];
        }
        ix = nxt(ix);
      }
    }

    indptr.assign(N + 1, 0);
    FOR(i, N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);
    keyY.resize(indptr.back());
    dat.resize(indptr.back());
    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i]) {
      keyY[indptr[i] + j] = keyY_raw[i][j];
      dat[indptr[i] + j] = dat_raw[i][j];
    }
    FOR(i, N) {
      int n = indptr[i + 1] - indptr[i];
      FOR(j, n - 1) {
        int k = nxt(j);
        if (k < n) dat[indptr[i] + k] += dat[indptr[i] + j];
      }
    }
  }

  void add_i(int i, ll y, T val) {
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int j = lower_bound(it, it + n, y) - it;
    assert(keyY[LID + j] == y);
    while (j < n) {
      dat[LID + j] += val;
      j = nxt(j);
    }
  }

  void add(ll x, ll y, T val) {
    int i = xtoi(x);
    assert(keyX[i] == x);
    while (i < N) {
      add_i(i, y, val);
      i = nxt(i);
    }
  }

  T sum_i(int i, ll ly, ll ry) {
    T ret = 0;
    int LID = indptr[i], n = indptr[i + 1] - indptr[i];
    auto it = keyY.begin() + LID;
    int L = lower_bound(it, it + n, ly) - it - 1;
    int R = lower_bound(it, it + n, ry) - it - 1;
    while (L < R) {
      ret += dat[LID + R];
      R = prev(R);
    }
    while (R < L) {
      ret -= dat[LID + L];
      L = prev(L);
    }
    return ret;
  }

  T sum(ll lx, ll rx, ll ly, ll ry) {
    T ret = 0;
    int L = xtoi(lx) - 1;
    int R = xtoi(rx) - 1;
    while (L < R) {
      ret += sum_i(R, ly, ry);
      R = prev(R);
    }
    while (R < L) {
      ret -= sum_i(L, ly, ry);
      L = prev(L);
    }
    return ret;
  }

  void debug() {
    print("keyX", keyX);
    print("indptr", indptr);
    print("keyY", keyY);
    print("dat", dat);
  }
};