---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/add_mul_lazy.hpp
    title: algebra/add_mul_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: other/rectanglesums.hpp
    title: other/rectanglesums.hpp
  _extendedVerifiedWith:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X ZERO = X(0)>\r\nstruct AddGroup {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return n * x; }\r\n\
    \  static constexpr X unit = ZERO;\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/addgroup.hpp
  requiredBy:
  - algebra/add_mul_lazy.hpp
  - other/rectanglesums.hpp
  timestamp: '2021-12-30 22:02:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_group.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/rectangle_sum_sweep.test.cpp
documentation_of: algebra/addgroup.hpp
layout: document
redirect_from:
- /library/algebra/addgroup.hpp
- /library/algebra/addgroup.hpp.html
title: algebra/addgroup.hpp
---