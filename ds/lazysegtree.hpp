#pragma once
#include "my_template.hpp"

#include "algebra/monoid.hpp"

template <typename E, typename OP>
struct LazySegTree {
  using F = function<E(E, E)>;
  using G = function<E(E, OP)>;
  using H = function<OP(OP, OP)>;
  int _n, size, log;
  vc<E> dat;
  vc<OP> laz;
  F seg_f;
  G seg_g;
  H seg_h;
  E unit;
  OP OP_unit;
  bool OP_commute;

  LazySegTree(Monoid_OP<E, OP> Mono)
      : seg_f(Mono.f),
        seg_g(Mono.g),
        seg_h(Mono.h),
        unit(Mono.unit),
        OP_unit(Mono.OP_unit),
        OP_commute(Mono.OP_commute) {}

  void init(int n) {
    _n = n;
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, unit);
    laz.assign(size, OP_unit);
  }

  void build(const vector<E>& v) {
    assert(len(v) == _n);
    FOR(i, len(v)) { dat[size + i] = v[i]; }
    FOR3_R(i, 1, size) { update(i); }
  }

  void update(int k) { dat[k] = seg_f(dat[2 * k], dat[2 * k + 1]); }

  void all_apply(int k, OP a) {
    dat[k] = seg_g(dat[k], a);
    if (k < size) laz[k] = seg_h(laz[k], a);
  }

  void push(int k) {
    all_apply(2 * k, laz[k]);
    all_apply(2 * k + 1, laz[k]);
    laz[k] = OP_unit;
  }

  void set(int p, E x) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    dat[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  E get(int p) {
    assert(0 <= p && p < _n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return dat[p];
  }

  E prod(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return unit;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    E sml = unit, smr = unit;
    while (l < r) {
      if (l & 1) sml = seg_f(sml, dat[l++]);
      if (r & 1) smr = seg_f(dat[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return seg_f(sml, smr);
  }

  E all_prod() { return dat[1]; }

  void apply(int p, OP a) {
    assert(0 <= p && p < _n);
    p += size;
    if (!OP_commute)
      for (int i = log; i >= 1; i--) push(p >> i);
    dat[p] = seg_g(dat[p], a);
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  void apply(int l, int r, OP a) {
    assert(0 <= l && l <= r && r <= _n);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, a);
        if (r & 1) all_apply(--r, a);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <typename C>
  int max_right(C& check, int l) {
    assert(0 <= l && l <= _n);
    assert(check(unit));
    if (l == _n) return _n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    E sm = unit;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!check(seg_f(sm, dat[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (check(seg_f(sm, dat[l]))) {
            sm = seg_f(sm, dat[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = seg_f(sm, dat[l]);
      l++;
    } while ((l & -l) != l);
    return _n;
  }

  template <typename C>
  int min_left(C& check, int r) {
    assert(0 <= r && r <= _n);
    assert(check(unit));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    E sm = unit;
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!check(seg_f(dat[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (check(seg_f(dat[r], sm))) {
            sm = seg_f(dat[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = seg_f(dat[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

  void debug() {
    vc<E> v(_n);
    FOR(i, _n) v[i] = get(i);
    print("lazysegtree getall:", v);
  }
};
