---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/add_mul_lazy.hpp
    title: algebra/add_mul_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickraq.hpp
    title: ds/fenwickraq.hpp
  - icon: ':heavy_check_mark:'
    path: graph/treeabelgroup.hpp
    title: graph/treeabelgroup.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038_centroid.test.cpp
    title: test/yukicoder/1038_centroid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
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
  path: algebra/addgroup.hpp
  requiredBy:
  - graph/treeabelgroup.hpp
  - algebra/add_mul_lazy.hpp
  - ds/fenwickraq.hpp
  - ds/fenwick.hpp
  - other/rectanglesums.hpp
  timestamp: '2022-01-01 19:12:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - test/yukicoder/899_bfsnumbering.test.cpp
  - test/yukicoder/1038_centroid.test.cpp
documentation_of: algebra/addgroup.hpp
layout: document
redirect_from:
- /library/algebra/addgroup.hpp
- /library/algebra/addgroup.hpp.html
title: algebra/addgroup.hpp
---
