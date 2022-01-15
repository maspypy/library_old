---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/lazy_add_mul.hpp
    title: alg/lazy_add_mul.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_cntminmincnt_add.hpp
    title: alg/lazy_cntminmincnt_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_add.hpp
    title: alg/lazy_min_add.hpp
  - icon: ':question:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':question:'
    path: ds/fenwick2d.hpp
    title: ds/fenwick2d.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickraq.hpp
    title: ds/fenwickraq.hpp
  - icon: ':x:'
    path: graph/treeabelgroup.hpp
    title: graph/treeabelgroup.hpp
  - icon: ':x:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectangleunion.hpp
    title: other/rectangleunion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G_fenwick_raq.test.cpp
    title: test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
    title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_4_A_rectangle_union.test.cpp
    title: test/aoj/DSL_4_A_rectangle_union.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
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
    path: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1038_centroid.test.cpp
    title: test/yukicoder/1038_centroid.test.cpp
  - icon: ':x:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
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
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X, X ZERO = X(0)>\r\nstruct Group_Add {\r\
    \n  using value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return n *\
    \ x; }\r\n  static constexpr X unit = ZERO;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_add.hpp
  requiredBy:
  - other/rectanglesums.hpp
  - other/rectangleunion.hpp
  - ds/fenwickraq.hpp
  - ds/fenwick.hpp
  - ds/fenwick2d.hpp
  - graph/treeabelgroup.hpp
  - alg/lazy_add_mul.hpp
  - alg/lazy_cntminmincnt_add.hpp
  - alg/lazy_min_add.hpp
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - test/aoj/DSL_4_A_rectangle_union.test.cpp
  - test/aoj/DSL_2_E_fenwick_raq.test.cpp
  - test/aoj/DSL_2_G_fenwick_raq.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test/library_checker/datastructure/staticf_range_inversions_mo.test.cpp
  - test/yukicoder/899_bfsnumbering.test.cpp
  - test/yukicoder/1038_centroid.test.cpp
documentation_of: alg/group_add.hpp
layout: document
redirect_from:
- /library/alg/group_add.hpp
- /library/alg/group_add.hpp.html
title: alg/group_add.hpp
---
