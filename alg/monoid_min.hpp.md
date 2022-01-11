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
  bundledCode: "#line 1 \"alg/monoid_min.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit = INF;\r\
    \n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct Monoid_Min {\r\n  using value_type =\
    \ X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit = INF;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min.hpp
  requiredBy: []
  timestamp: '2022-01-11 13:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_min.hpp
layout: document
redirect_from:
- /library/alg/monoid_min.hpp
- /library/alg/monoid_min.hpp.html
title: alg/monoid_min.hpp
---
