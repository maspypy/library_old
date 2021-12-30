---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/fenwick.hpp\"\ntemplate <typename AbelGroup>\nstruct\
    \ FenwickTree {\n  using E = typename AbelGroup::value_type;\n  int n;\n  vector<E>\
    \ dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int n)\
    \ : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat.assign(n\
    \ + 1, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit)\
    \ {\n    assert(AbelGroup::commute);\n    dat.assign(n + 1, AbelGroup::unit);\n\
    \    FOR(i, n) dat[i + 1] = v[i];\n    FOR3(i, 1, n + 1) {\n      int j = i +\
    \ (i & -i);\n      if (j <= n) dat[j] = AbelGroup::op(dat[i], dat[j]);\n    }\n\
    \  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit;\n    for (; k > 0; k -=\
    \ k & -k) ret = AbelGroup::op(ret, dat[k]);\n    return ret;\n  }\n\n  E sum(int\
    \ L, int R) {\n    E pos = AbelGroup::unit;\n    while (L < R) {\n      pos =\
    \ AbelGroup::op(pos, dat[R]);\n      R -= R & -R;\n    }\n    E neg = AbelGroup::unit;\n\
    \    while (R < L) {\n      neg = AbelGroup::op(neg, dat[L]);\n      L -= L &\
    \ -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n  }\n\n\
    \  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total = AbelGroup::op(total,\
    \ x);\n    for (++k; k < len(dat); k += k & -k) dat[k] = AbelGroup::op(dat[k],\
    \ x);\n  }\n\n  template <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n\
    \    ll i = 0;\n    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat);\n\
    \    while (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i]);\n  \
    \    }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n"
  code: "#pragma once\ntemplate <typename AbelGroup>\nstruct FenwickTree {\n  using\
    \ E = typename AbelGroup::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\
    \n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int n) : n(n), total(AbelGroup::unit)\
    \ {\n    assert(AbelGroup::commute);\n    dat.assign(n + 1, AbelGroup::unit);\n\
    \  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n + 1, AbelGroup::unit);\n    FOR(i, n) dat[i + 1] = v[i];\n \
    \   FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j]\
    \ = AbelGroup::op(dat[i], dat[j]);\n    }\n  }\n\n  E sum(int k) {\n    E ret\
    \ = AbelGroup::unit;\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k]);\n    return ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n\
    \    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R]);\n      R -= R &\
    \ -R;\n    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total\
    \ = AbelGroup::op(total, x);\n    for (++k; k < len(dat); k += k & -k) dat[k]\
    \ = AbelGroup::op(dat[k], x);\n  }\n\n  template <class F>\n  int max_right(F&\
    \ check) {\n    assert(f(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit;\n\
    \    int k = 1;\n    int N = len(dat);\n    while (2 * k < N) k *= 2;\n    while\
    \ (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k]))) {\n     \
    \   i += k;\n        s = AbelGroup::op(s, dat[i]);\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int find_kth_element(E k) {\n    auto check =\
    \ [&](E x) -> bool { return x < k; };\n    return max_right(check);\n  }\n\n \
    \ void debug() { print(\"fenwick\", dat); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick.hpp
  requiredBy:
  - other/rectanglesums.hpp
  timestamp: '2021-12-30 22:02:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
documentation_of: ds/fenwick.hpp
layout: document
redirect_from:
- /library/ds/fenwick.hpp
- /library/ds/fenwick.hpp.html
title: ds/fenwick.hpp
---
