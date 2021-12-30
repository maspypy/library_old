---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: algebra/add_mul_lazy.hpp
    title: algebra/add_mul_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - algebra/add_mul_lazy.hpp
  timestamp: '2021-12-30 20:02:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/899_bfsnumbering.test.cpp
documentation_of: algebra/mulgroup.hpp
layout: document
redirect_from:
- /library/algebra/mulgroup.hpp
- /library/algebra/mulgroup.hpp.html
title: algebra/mulgroup.hpp
---
