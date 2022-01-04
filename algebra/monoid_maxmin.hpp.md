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
  bundledCode: "#line 1 \"algebra/monoid_maxmin.hpp\"\ntemplate <class X, X INF>\r\
    \nstruct Monoid_MaxMin {\r\n  using P = pair<X, X>;\r\n  using value_type = P;\r\
    \n  static constexpr P op(const P x, const P y) noexcept { return {max(x.fi, y.fi),\
    \ min(x.se, y.se)}; }\r\n  static constexpr P unit = P({-INF, INF});\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct Monoid_MaxMin {\r\n  using P = pair<X,\
    \ X>;\r\n  using value_type = P;\r\n  static constexpr P op(const P x, const P\
    \ y) noexcept { return {max(x.fi, y.fi), min(x.se, y.se)}; }\r\n  static constexpr\
    \ P unit = P({-INF, INF});\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_maxmin.hpp
  requiredBy: []
  timestamp: '2022-01-04 19:49:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_maxmin.hpp
layout: document
redirect_from:
- /library/algebra/monoid_maxmin.hpp
- /library/algebra/monoid_maxmin.hpp.html
title: algebra/monoid_maxmin.hpp
---
