#pragma once
template <typename T, typename OP, bool OP_commute = false>
struct LazySegTree {
  using F = function<T(T, T)>;
  using G = function<T(T, OP)>;
  using H = function<OP(OP, OP)>;
  int sz, n, height;
  F f;
  G g;
  H h;
  T ti;
  OP ei;
  vector<T> dat;
  vector<OP> laz;
  LazySegTree(F f, G g, H h, T ti, OP ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}

  void init(int n_) {
    sz = n_;
    n = 1;
    height = 0;
    while (n < n_) n <<= 1, height++;
    dat.assign(2 * n, ti);
    laz.assign(2 * n, ei);
  }

  void build(const vector<T> &v) {
    int n_ = v.size();
    init(n_);
    for (int i = 0; i < n_; i++) dat[n + i] = v[i];
    for (int i = n - 1; i; i--)
      dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
  }

  inline T reflect(int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }

  inline void propagate(int k) {
    if (laz[k] == ei) return;
    laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
    laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
    dat[k] = reflect(k);
    laz[k] = ei;
  }

  inline void thrust(int k) {
    for (int i = height; i; i--) propagate(k >> i);
  }

  inline void recalc(int k) {
    while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
  }

  void operate_range(int a, int b, OP x) {
    if (a >= b) return;
    a += n, b += n - 1;
    if (!OP_commute) {
      thrust(a);
      thrust(b);
    }
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) laz[l] = h(laz[l], x), l++;
      if (r & 1) --r, laz[r] = h(laz[r], x);
    }
    recalc(a);
    recalc(b);
  }

  void set(int a, T x) {
    thrust(a += n);
    dat[a] = x;
    laz[a] = ei;
    recalc(a);
  }

  T fold(int a, int b) {
    if (a >= b) return ti;
    thrust(a += n);
    thrust(b += n - 1);
    T vl = ti, vr = ti;
    for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = f(vl, reflect(l++));
      if (r & 1) vr = f(reflect(--r), vr);
    }
    return f(vl, vr);
  }

  template <typename C>
  int find(int st, C &check, T &acc, int k, int l, int r) {
    if (l + 1 == r) {
      acc = f(acc, reflect(k));
      return check(acc) ? k - n : -1;
    }
    propagate(k);
    int m = (l + r) >> 1;
    if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
    if (st <= l and !check(f(acc, dat[k]))) {
      acc = f(acc, dat[k]);
      return -1;
    }
    int vl = find(st, check, acc, (k << 1) | 0, l, m);
    if (~vl) return vl;
    return find(st, check, acc, (k << 1) | 1, m, r);
  }

  template <typename C>
  int find(int st, C &check) {
    T acc = ti;
    return find(st, check, acc, 1, 0, n);
  }

  void debug() {
    vc<T> A(sz);
    FOR(i, sz) A[i] = fold(i, i + 1);
    print(A);
  }
};
