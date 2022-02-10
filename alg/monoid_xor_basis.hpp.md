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
  bundledCode: "#line 1 \"alg/monoid_xor_basis.hpp\"\n\r\nstruct Monoid_XorBasis {\r\
    \n  using value_type = vc<int>;\r\n  using X = value_type;\r\n  static X op(X\
    \ x, X y) {\r\n    for (auto&& v: y) {\r\n      for (auto&& w: x) chmin(v, v ^\
    \ w);\r\n      if (v) x.eb(v);\r\n    }\r\n    return x;\r\n  }\r\n  static const\
    \ X unit;\r\n  static constexpr bool commute = true;\r\n};\r\nconst vc<int> Monoid_XorBasis::unit;\n"
  code: "\r\nstruct Monoid_XorBasis {\r\n  using value_type = vc<int>;\r\n  using\
    \ X = value_type;\r\n  static X op(X x, X y) {\r\n    for (auto&& v: y) {\r\n\
    \      for (auto&& w: x) chmin(v, v ^ w);\r\n      if (v) x.eb(v);\r\n    }\r\n\
    \    return x;\r\n  }\r\n  static const X unit;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\nconst vc<int> Monoid_XorBasis::unit;"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_xor_basis.hpp
  requiredBy: []
  timestamp: '2022-02-11 06:54:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_xor_basis.hpp
layout: document
redirect_from:
- /library/alg/monoid_xor_basis.hpp
- /library/alg/monoid_xor_basis.hpp.html
title: alg/monoid_xor_basis.hpp
---
