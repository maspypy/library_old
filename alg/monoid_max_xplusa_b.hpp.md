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
  bundledCode: "#line 1 \"alg/monoid_max_xplusa_b.hpp\"\ntemplate <typename T, T INF>\r\
    \nstruct Monoid_Max_xplusa_b {\r\n  using value_type = pi;\r\n  using X = value_type;\r\
    \n  static X op(X A, X B) {\r\n    auto [a, b] = A;\r\n    auto [c, d] = B;\r\n\
    \    ll e = a + c, f = max(b + c, d);\r\n    chmax(e, -INF);\r\n    chmax(f, -INF);\r\
    \n    return {e, f};\r\n  }\r\n  static constexpr X unit = X(0, -INF);\r\n  static\
    \ constexpr bool commute = false;\r\n};\n"
  code: "template <typename T, T INF>\r\nstruct Monoid_Max_xplusa_b {\r\n  using value_type\
    \ = pi;\r\n  using X = value_type;\r\n  static X op(X A, X B) {\r\n    auto [a,\
    \ b] = A;\r\n    auto [c, d] = B;\r\n    ll e = a + c, f = max(b + c, d);\r\n\
    \    chmax(e, -INF);\r\n    chmax(f, -INF);\r\n    return {e, f};\r\n  }\r\n \
    \ static constexpr X unit = X(0, -INF);\r\n  static constexpr bool commute = false;\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max_xplusa_b.hpp
  requiredBy: []
  timestamp: '2022-03-07 00:57:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_max_xplusa_b.hpp
layout: document
redirect_from:
- /library/alg/monoid_max_xplusa_b.hpp
- /library/alg/monoid_max_xplusa_b.hpp.html
title: alg/monoid_max_xplusa_b.hpp
---
