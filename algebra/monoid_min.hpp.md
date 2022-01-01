---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_max_set.hpp
    title: algebra/lazy_max_set.hpp
  - icon: ':x:'
    path: algebra/lazy_min_add.hpp
    title: algebra/lazy_min_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_min_set.hpp
    title: algebra/lazy_min_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
    title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_min.hpp\"\ntemplate <class X, X INF>\r\n\
    struct MinMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit\
    \ = INF;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct MinMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit = INF;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_min.hpp
  requiredBy:
  - algebra/lazy_min_add.hpp
  - algebra/lazy_max_set.hpp
  - algebra/lazy_min_set.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
documentation_of: algebra/monoid_min.hpp
layout: document
redirect_from:
- /library/algebra/monoid_min.hpp
- /library/algebra/monoid_min.hpp.html
title: algebra/monoid_min.hpp
---
