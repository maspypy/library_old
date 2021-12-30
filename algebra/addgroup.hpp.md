---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_add_mul.hpp
    title: algebra/lazy_add_mul.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/addgroup.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X ZERO = X(0)>\r\nstruct AddGroup {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X unit = ZERO;\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/addgroup.hpp
  requiredBy:
  - algebra/lazy_add_mul.hpp
  timestamp: '2021-12-28 17:04:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/addgroup.hpp
layout: document
redirect_from:
- /library/algebra/addgroup.hpp
- /library/algebra/addgroup.hpp.html
title: algebra/addgroup.hpp
---
