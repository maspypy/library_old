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
  bundledCode: "#line 1 \"algebra/mulgroup.hpp\"\ntemplate <class X, X ONE = X(1)>\r\
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
  path: algebra/mulgroup.hpp
  requiredBy:
  - algebra/lazy_add_mul.hpp
  timestamp: '2021-12-30 20:02:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/mulgroup.hpp
layout: document
redirect_from:
- /library/algebra/mulgroup.hpp
- /library/algebra/mulgroup.hpp.html
title: algebra/mulgroup.hpp
---
