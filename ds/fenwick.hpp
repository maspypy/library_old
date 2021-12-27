#pragma once
template <typename T>
struct FenwickTree {
  vector<T> data;
  T total;

  FenwickTree() : total(0) {}
  FenwickTree(int sz) : total(0) { data.assign(++sz, 0); }

  void init(int n) { data.assign(++n, 0); }

  void build(vector<T>& raw_data) {
    assert(len(data) == len(raw_data) + 1);
    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];
    FOR(i, len(data)) {
      int j = i + (i & -i);
      if (j < len(data)) data[j] += data[i];
    }
  }

  T sum(int k) {
    T ret = 0;
    for (; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  T sum(int L, int R) {
    T ret = 0;
    while (L < R) {
      ret += data[R];
      R -= R & -R;
    }
    while (R < L) {
      ret -= data[L];
      L -= L & -L;
    }
    return ret;
  }

  T sum_all() { return total; }

  void add(int k, T x) {
    total += x;
    for (++k; k < len(data); k += k & -k) data[k] += x;
  }

  template <class F>
  int max_right(F& check) {
    assert(f(T(0)));
    ll i = 0;
    T s = 0;
    int k = 1;
    int N = len(data);
    while (2 * k < N) k *= 2;
    while (k) {
      if (i + k < N && check(s + data[i + k])) {
        i += k;
        s += data[i];
      }
      k >>= 1;
    }
    return i;
  }

  int find_kth_element(T k) {
    auto check = [&](T x) -> bool { return x < k; };
    return max_right(check);
  }

  void debug() { print(data); }
};

template <typename T>
struct Fenwick_RAQ {
  int N;
  FenwickTree<T> bit0;
  FenwickTree<T> bit1;

  Fenwick_RAQ(int N) : N(N), bit0(N), bit1(N) {}
  Fenwick_RAQ() {}

  void init(int n) {
    N = n;
    bit0.init(n);
    bit1.init(n);
  }

  void build(vc<T>& v) { bit0.build(v); }

  void add_at(ll i, T val) { bit0.add(i, val); }

  void add_range(ll L, ll R, T val) {
    bit0.add(L, -val * L);
    bit1.add(L, +val);
    bit0.add(R, +val * R);
    bit1.add(R, -val);
  }

  T sum(ll L, ll R) {
    T sum_R = R * bit1.sum(R) + bit0.sum(R);
    T sum_L = L * bit1.sum(L) + bit0.sum(L);
    return sum_R - sum_L;
  }
};
