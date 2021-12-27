---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/treeabel.hpp
    title: graph/treeabel.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fenwick.hpp\"\ntemplate <typename T>\nstruct FenwickTree\
    \ {\n  vector<T> data;\n  T total;\n\n  FenwickTree() : total(0) {}\n  FenwickTree(int\
    \ sz) : total(0) { data.assign(++sz, 0); }\n\n  void init(int n) { data.assign(++n,\
    \ 0); }\n\n  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data)\
    \ + 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < len(data); k += k & -k) data[k] += x;\n  }\n\
    \n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n  \
    \  ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(data); }\n};\n\ntemplate <typename T>\nstruct Fenwick_RAQ\
    \ {\n  int N;\n  FenwickTree<T> bit0;\n  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int\
    \ N) : N(N), bit0(N), bit1(N) {}\n  Fenwick_RAQ() {}\n\n  void init(int n) {\n\
    \    N = n;\n    bit0.init(n);\n    bit1.init(n);\n  }\n\n  void build(vc<T>&\
    \ v) { bit0.build(v); }\n\n  void add_at(ll i, T val) { bit0.add(i, val); }\n\n\
    \  void add_range(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct FenwickTree {\n  vector<T> data;\n\
    \  T total;\n\n  FenwickTree() : total(0) {}\n  FenwickTree(int sz) : total(0)\
    \ { data.assign(++sz, 0); }\n\n  void init(int n) { data.assign(++n, 0); }\n\n\
    \  void build(vector<T>& raw_data) {\n    assert(len(data) == len(raw_data) +\
    \ 1);\n    FOR(i, len(raw_data)) data[i + 1] = raw_data[i];\n    FOR(i, len(data))\
    \ {\n      int j = i + (i & -i);\n      if (j < len(data)) data[j] += data[i];\n\
    \    }\n  }\n\n  T sum(int k) {\n    T ret = 0;\n    for (; k > 0; k -= k & -k)\
    \ ret += data[k];\n    return (ret);\n  }\n\n  T sum(int L, int R) {\n    T ret\
    \ = 0;\n    while (L < R) {\n      ret += data[R];\n      R -= R & -R;\n    }\n\
    \    while (R < L) {\n      ret -= data[L];\n      L -= L & -L;\n    }\n    return\
    \ ret;\n  }\n\n  T sum_all() { return total; }\n\n  void add(int k, T x) {\n \
    \   total += x;\n    for (++k; k < len(data); k += k & -k) data[k] += x;\n  }\n\
    \n  template <class F>\n  int max_right(F& check) {\n    assert(f(T(0)));\n  \
    \  ll i = 0;\n    T s = 0;\n    int k = 1;\n    int N = len(data);\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(s + data[i\
    \ + k])) {\n        i += k;\n        s += data[i];\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(T k) {\n    auto check =\
    \ [&](T x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(data); }\n};\n\ntemplate <typename T>\nstruct Fenwick_RAQ\
    \ {\n  int N;\n  FenwickTree<T> bit0;\n  FenwickTree<T> bit1;\n\n  Fenwick_RAQ(int\
    \ N) : N(N), bit0(N), bit1(N) {}\n  Fenwick_RAQ() {}\n\n  void init(int n) {\n\
    \    N = n;\n    bit0.init(n);\n    bit1.init(n);\n  }\n\n  void build(vc<T>&\
    \ v) { bit0.build(v); }\n\n  void add_at(ll i, T val) { bit0.add(i, val); }\n\n\
    \  void add_range(ll L, ll R, T val) {\n    bit0.add(L, -val * L);\n    bit1.add(L,\
    \ +val);\n    bit0.add(R, +val * R);\n    bit1.add(R, -val);\n  }\n\n  T sum(ll\
    \ L, ll R) {\n    T sum_R = R * bit1.sum(R) + bit0.sum(R);\n    T sum_L = L *\
    \ bit1.sum(L) + bit0.sum(L);\n    return sum_R - sum_L;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick.hpp
  requiredBy:
  - graph/treeabel.hpp
  - other/rectanglesums.hpp
  timestamp: '2021-12-27 18:40:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
documentation_of: ds/fenwick.hpp
layout: document
redirect_from:
- /library/ds/fenwick.hpp
- /library/ds/fenwick.hpp.html
title: ds/fenwick.hpp
---
