---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/fenwickraq.hpp
    title: ds/fenwickraq.hpp
  - icon: ':x:'
    path: graph/treeabelgroup.hpp
    title: graph/treeabelgroup.hpp
  - icon: ':x:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
    title: test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1038_centroid.test.cpp
    title: test/yukicoder/1038_centroid.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwick.hpp\"\n\ntemplate\
    \ <typename AbelGroup>\nstruct FenwickTree {\n  using E = typename AbelGroup::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n\
    \  FenwickTree(int n) : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n\
    \    dat.assign(n, AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)),\
    \ total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat = v;\n  \
    \  FOR3(i, 1, n + 1) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j -\
    \ 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);\n    }\n  }\n\n  E sum(int k) {\n\
    \    E ret = AbelGroup::unit;\n    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret,\
    \ dat[k - 1]);\n    return ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n\
    \    while (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -=\
    \ R & -R;\n    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg\
    \ = AbelGroup::op(neg, dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\n  }\n\n  E sum_all() { return total; }\n\n  void\
    \ add(int k, E x) {\n    total = AbelGroup::op(total, x);\n    for (++k; k <=\
    \ n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);\n  }\n\n  template\
    \ <class F>\n  int max_right(F& check) {\n    assert(f(E(0)));\n    ll i = 0;\n\
    \    E s = AbelGroup::unit;\n    int k = 1;\n    int N = len(dat) + 1;\n    while\
    \ (2 * k < N) k *= 2;\n    while (k) {\n      if (i + k < N && check(AbelGroup::op(s,\
    \ dat[i + k - 1]))) {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n\
    \      }\n      k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E\
    \ k) {\n    auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};\n"
  code: "#pragma once\n#include \"alg/group_add.hpp\"\n\ntemplate <typename AbelGroup>\n\
    struct FenwickTree {\n  using E = typename AbelGroup::value_type;\n  int n;\n\
    \  vector<E> dat;\n  E total;\n\n  FenwickTree() : FenwickTree(0) {}\n  FenwickTree(int\
    \ n) : n(n), total(AbelGroup::unit) {\n    assert(AbelGroup::commute);\n    dat.assign(n,\
    \ AbelGroup::unit);\n  }\n  FenwickTree(vc<E> v) : n(len(v)), total(AbelGroup::unit)\
    \ {\n    assert(AbelGroup::commute);\n    dat = v;\n    FOR3(i, 1, n + 1) {\n\
    \      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i\
    \ - 1], dat[j - 1]);\n    }\n  }\n\n  E sum(int k) {\n    E ret = AbelGroup::unit;\n\
    \    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);\n    return\
    \ ret;\n  }\n\n  E sum(int L, int R) {\n    E pos = AbelGroup::unit;\n    while\
    \ (L < R) {\n      pos = AbelGroup::op(pos, dat[R - 1]);\n      R -= R & -R;\n\
    \    }\n    E neg = AbelGroup::unit;\n    while (R < L) {\n      neg = AbelGroup::op(neg,\
    \ dat[L - 1]);\n      L -= L & -L;\n    }\n    return AbelGroup::op(pos, AbelGroup::inverse(neg));\n\
    \  }\n\n  E sum_all() { return total; }\n\n  void add(int k, E x) {\n    total\
    \ = AbelGroup::op(total, x);\n    for (++k; k <= n; k += k & -k) dat[k - 1] =\
    \ AbelGroup::op(dat[k - 1], x);\n  }\n\n  template <class F>\n  int max_right(F&\
    \ check) {\n    assert(f(E(0)));\n    ll i = 0;\n    E s = AbelGroup::unit;\n\
    \    int k = 1;\n    int N = len(dat) + 1;\n    while (2 * k < N) k *= 2;\n  \
    \  while (k) {\n      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1])))\
    \ {\n        i += k;\n        s = AbelGroup::op(s, dat[i - 1]);\n      }\n   \
    \   k >>= 1;\n    }\n    return i;\n  }\n\n  int find_kth_element(E k) {\n   \
    \ auto check = [&](E x) -> bool { return x < k; };\n    return max_right(check);\n\
    \  }\n\n  void debug() { print(\"fenwick\", dat); }\n};"
  dependsOn:
  - alg/group_add.hpp
  isVerificationFile: false
  path: ds/fenwick.hpp
  requiredBy:
  - other/rectanglesums.hpp
  - ds/fenwickraq.hpp
  - graph/treeabelgroup.hpp
  timestamp: '2022-01-11 13:47:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
  - test/yukicoder/1038_centroid.test.cpp
documentation_of: ds/fenwick.hpp
layout: document
redirect_from:
- /library/ds/fenwick.hpp
- /library/ds/fenwick.hpp.html
title: ds/fenwick.hpp
---
