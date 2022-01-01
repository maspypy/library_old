---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/max_set_lazy.hpp
    title: algebra/max_set_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/min_add_lazy.hpp
    title: algebra/min_add_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/min_set_lazy.hpp
    title: algebra/min_set_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
    title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/minmonoid.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ MinMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit = INF;\r\
    \n};\r\n"
  code: "template <class X, X INF>\r\nstruct MinMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit = INF;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/minmonoid.hpp
  requiredBy:
  - algebra/min_set_lazy.hpp
  - algebra/max_set_lazy.hpp
  - algebra/min_add_lazy.hpp
  timestamp: '2021-12-28 08:10:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
documentation_of: algebra/minmonoid.hpp
layout: document
redirect_from:
- /library/algebra/minmonoid.hpp
- /library/algebra/minmonoid.hpp.html
title: algebra/minmonoid.hpp
---
