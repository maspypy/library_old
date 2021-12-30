#pragma once
template <typename AbelGroup>
struct FenwickTree {
  using E = typename AbelGroup::value_type;
  int n;
  vector<E> dat;
  E total;

  FenwickTree() : FenwickTree(0) {}
  FenwickTree(int n) : n(n), total(AbelGroup::unit) {
    assert(AbelGroup::commute);
    dat.assign(n + 1, AbelGroup::unit);
  }
  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit) {
    assert(AbelGroup::commute);
    dat.assign(n + 1, AbelGroup::unit);
    FOR(i, n) dat[i + 1] = v[i];
    FOR3(i, 1, n + 1) {
      int j = i + (i & -i);
      if (j <= n) dat[j] = AbelGroup::op(dat[i], dat[j]);
    }
  }

  E sum(int k) {
    E ret = AbelGroup::unit;
    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k]);
    return ret;
  }

  E sum(int L, int R) {
    E pos = AbelGroup::unit;
    while (L < R) {
      pos = AbelGroup::op(pos, dat[R]);
      R -= R & -R;
    }
    E neg = AbelGroup::unit;
    while (R < L) {
      neg = AbelGroup::op(neg, dat[L]);
      L -= L & -L;
    }
    return AbelGroup::op(pos, AbelGroup::inverse(neg));
  }

  E sum_all() { return total; }

  void add(int k, E x) {
    total = AbelGroup::op(total, x);
    for (++k; k < len(dat); k += k & -k) dat[k] = AbelGroup::op(dat[k], x);
  }

  template <class F>
  int max_right(F& check) {
    assert(f(E(0)));
    ll i = 0;
    E s = AbelGroup::unit;
    int k = 1;
    int N = len(dat);
    while (2 * k < N) k *= 2;
    while (k) {
      if (i + k < N && check(AbelGroup::op(s, dat[i + k]))) {
        i += k;
        s = AbelGroup::op(s, dat[i]);
      }
      k >>= 1;
    }
    return i;
  }

  int find_kth_element(E k) {
    auto check = [&](E x) -> bool { return x < k; };
    return max_right(check);
  }

  void debug() { print("fenwick", dat); }
};