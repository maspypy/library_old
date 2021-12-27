#pragma once
#include "algebra/monoid.hpp"

template <typename E>
struct SegTree {
  using F = function<E(E, E)>;
  int N_;
  int N;
  F seg_f;
  E unit;
  vector<E> dat;

  SegTree(Monoid<E> Mono) : seg_f(Mono.f), unit(Mono.unit) {}

  void init(int n_) {
    N_ = n_;
    N = 1;
    while (N < n_) N <<= 1;
    dat.assign(N << 1, unit);
  }

  void build(const vector<E> &v) {
    assert(len(v) == N_);
    FOR(i, len(v)) { dat[N + i] = v[i]; }
    FOR3_R(i, 1, N) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }
  }

  void set(int i, E x) {
    assert(i < N_);
    dat[i += N] = x;
    while (i >>= 1) { dat[i] = seg_f(dat[i << 1 | 0], dat[i << 1 | 1]); }
  }

  E prod(int L, int R) {
    assert(L <= R);
    assert(R <= N_);
    E vl = unit, vr = unit;
    L += N;
    R += N;
    while (L < R) {
      if (L & 1) vl = seg_f(vl, dat[L++]);
      if (R & 1) vr = seg_f(dat[--R], vr);
      L >>= 1;
      R >>= 1;
    }
    return seg_f(vl, vr);
  }

  template <class F>
  int max_right(F &check, int L) {
    assert(0 <= L && L <= N_ && check(unit));
    if (L == N_) return N_;
    L += N;
    E sm = unit;
    do {
      while (L % 2 == 0) L >>= 1;
      if (!check(seg_f(sm, dat[L]))) {
        while (L < N) {
          L = 2 * L;
          if (check(seg_f(sm, dat[L]))) {
            sm = seg_f(sm, dat[L]);
            L++;
          }
        }
        return L - N;
      }
      sm = seg_f(sm, dat[L]);
      L++;
    } while ((L & -L) != L);
    return N_;
  }

  template <class F>
  int min_left(F &check, int R) {
    assert(0 <= R && R <= N_ && check(unit));
    if (R == 0) return 0;
    R += N;
    E sm = unit;
    do {
      --R;
      while (R > 1 && (R % 2)) R >>= 1;
      if (!check(seg_f(dat[R], sm))) {
        while (R < N) {
          R = 2 * R + 1;
          if (check(seg_f(dat[R], sm))) {
            sm = seg_f(dat[R], sm);
            R--;
          }
        }
        return R + 1 - N;
      }
      sm = seg_f(dat[R], sm);
    } while ((R & -R) != R);
    return 0;
  }

  void debug() { print(dat); }
};
