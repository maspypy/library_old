---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebraic_system/maxmonoid.hpp\"\ntemplate <class X, X INF>\r\
    \nstruct MaxMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit\
    \ = -INF;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct MaxMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y);\
    \ }\r\n  static constexpr X unit = -INF;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebraic_system/maxmonoid.hpp
  requiredBy: []
  timestamp: '2021-12-28 05:37:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic_system/maxmonoid.hpp
layout: document
redirect_from:
- /library/algebraic_system/maxmonoid.hpp
- /library/algebraic_system/maxmonoid.hpp.html
title: algebraic_system/maxmonoid.hpp
---
