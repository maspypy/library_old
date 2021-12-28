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
  bundledCode: "#line 1 \"algebra/maxmonoid.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ MaxMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit = -INF;\r\
    \n  static bool commute = true;\r\n};\r\n"
  code: "template <class X, X INF>\r\nstruct MaxMonoid {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return max(x, y);\
    \ }\r\n  static constexpr X unit = -INF;\r\n  static bool commute = true;\r\n\
    };\r\n"
  dependsOn: []
  isVerificationFile: false
  path: algebra/maxmonoid.hpp
  requiredBy: []
  timestamp: '2021-12-28 16:01:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/maxmonoid.hpp
layout: document
redirect_from:
- /library/algebra/maxmonoid.hpp
- /library/algebra/maxmonoid.hpp.html
title: algebra/maxmonoid.hpp
---
