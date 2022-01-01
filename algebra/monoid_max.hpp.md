---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_max_max.hpp
    title: algebra/lazy_max_max.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_max.hpp\"\ntemplate <class X, X INF>\r\n\
    struct Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit\
    \ = -INF;\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct Monoid_Max {\r\n  using value_type =\
    \ X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\r\n  static constexpr X unit = -INF;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_max.hpp
  requiredBy:
  - algebra/lazy_max_max.hpp
  timestamp: '2022-01-01 23:37:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_max.hpp
layout: document
redirect_from:
- /library/algebra/monoid_max.hpp
- /library/algebra/monoid_max.hpp.html
title: algebra/monoid_max.hpp
---
