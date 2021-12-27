---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebraic_system/minmonoid.hpp\"\ntemplate <class X, X INF>\r\
    \nstruct MinMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit\
    \ = INF;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct MinMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit = INF;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebraic_system/minmonoid.hpp
  requiredBy: []
  timestamp: '2021-12-28 05:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
documentation_of: algebraic_system/minmonoid.hpp
layout: document
redirect_from:
- /library/algebraic_system/minmonoid.hpp
- /library/algebraic_system/minmonoid.hpp.html
title: algebraic_system/minmonoid.hpp
---
