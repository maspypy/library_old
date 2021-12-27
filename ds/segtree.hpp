#pragma once
template <class M>
struct SegTree {
  using X = typename M::value_type;
  using value_type = X;
  vc<X> dat;
  int n, log, size;

  SegTree() : SegTree(0) {}
  SegTree(int n) : SegTree(vc<X>(n, M::unit)) {}
  SegTree(vc<X> &v) : n(len(v)) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, M::unit);
    FOR(i, n) dat[size + i] = v[i];
    FOR3_R(i, 1, size) update(i);
  }

  void update(int i) { dat[i] = M::op(dat[2 * i], dat[2 * i + 1]); }

  void set(int i, X x) {
    assert(i < n);
    dat[i += size] = x;
    while (i >>= 1) update(i);
  }

  X prod(int L, int R) {
    assert(L <= R);
    assert(R <= n);
    X vl = M::unit, vr = M::unit;
    L += size, R += size;
    while (L < R) {
      if (L & 1) vl = M::op(vl, dat[L++]);
      if (R & 1) vr = M::op(dat[--R], vr);
      L >>= 1, R >>= 1;
    }
    return M::op(vl, vr);
  }

  template <class F>
  int max_right(F &check, int L) {
    assert(0 <= L && L <= n && check(M::unit));
    if (L == n) return n;
    L += size;
    X sm = M::unit;
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(M::op(sm, dat[L]))) {
        while (L < n) {
          L = 2 * L;
          if (check(M::op(sm, dat[L]))) {
            sm = M::op(sm, dat[L]);
            L++;
          }
        }
        return L - n;
      }
      sm = M::op(sm, dat[L]);
      L++;
    } while ((L & -L) != L);
    return n;
  }

  template <class F>
  int min_left(F &check, int R) {
    assert(0 <= R && R <= n && check(M::unit));
    if (R == 0) return 0;
    R += n;
    X sm = M::unit;
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(M::op(dat[R], sm))) {
        while (R < n) {
          R = 2 * R + 1;
          if (check(M::op(dat[R], sm))) {
            sm = M::op(dat[R], sm);
            R--;
          }
        }
        return R + 1 - n;
      }
      sm = M::op(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  void debug() { print("segtree", dat); }
};