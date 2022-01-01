---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_add_mul.hpp
    title: algebra/lazy_add_mul.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/group_mul.hpp\"\ntemplate <class X, X ONE = X(1)>\r\
    \nstruct MulGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit = ONE;\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X ONE = X(1)>\r\nstruct MulGroup {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ * y; }\r\n  static constexpr X inverse(const X &x) noexcept { return X(1) /\
    \ x; }\r\n  static constexpr X unit = ONE;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/group_mul.hpp
  requiredBy:
  - algebra/lazy_add_mul.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/group_mul.hpp
layout: document
redirect_from:
- /library/algebra/group_mul.hpp
- /library/algebra/group_mul.hpp.html
title: algebra/group_mul.hpp
---
