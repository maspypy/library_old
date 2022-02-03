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
  bundledCode: "#line 1 \"alg/monoid_xor.hpp\"\ntemplate <typename T=long long>\r\n\
    struct Monoid_Xor {\r\n  using value_type = T;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return x ^ y; }\r\n  static constexpr X unit = X(0);\r\
    \n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename T=long long>\r\nstruct Monoid_Xor {\r\n  using value_type\
    \ = T;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return x ^ y; }\r\
    \n  static constexpr X unit = X(0);\r\n  static constexpr bool commute = true;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_xor.hpp
  requiredBy: []
  timestamp: '2022-02-03 13:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_xor.hpp
layout: document
redirect_from:
- /library/alg/monoid_xor.hpp
- /library/alg/monoid_xor.hpp.html
title: alg/monoid_xor.hpp
---
