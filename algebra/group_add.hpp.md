---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_add_mul.hpp
    title: algebra/lazy_add_mul.hpp
  - icon: ':warning:'
    path: algebra/lazy_min_add.hpp
    title: algebra/lazy_min_add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickraq.hpp
    title: ds/fenwickraq.hpp
  - icon: ':warning:'
    path: graph/treeabelgroup.hpp
    title: graph/treeabelgroup.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X, X ZERO = X(0)>\r\nstruct AddGroup {\r\n\
    \  using value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return n *\
    \ x; }\r\n  static constexpr X unit = ZERO;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_add.hpp
  requiredBy:
  - graph/treeabelgroup.hpp
  - algebra/lazy_add_mul.hpp
  - algebra/lazy_min_add.hpp
  - ds/fenwickraq.hpp
  - ds/fenwick.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
documentation_of: algebra/group_add.hpp
layout: document
redirect_from:
- /library/algebra/group_add.hpp
- /library/algebra/group_add.hpp.html
title: algebra/group_add.hpp
---
