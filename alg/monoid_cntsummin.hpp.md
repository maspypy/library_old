---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_cntsummin_add.hpp
    title: alg/lazy_cntsummin_add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_cntsummin.hpp\"\nstruct Monoid_CntSumMin {\r\n\
    \  static constexpr ll INF = 1LL << 60;\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc,\
    \ xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys,\
    \ min(xm, ym)};\r\n  }\r\n  static constexpr X unit = X({0, 0, INF});\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "struct Monoid_CntSumMin {\r\n  static constexpr ll INF = 1LL << 60;\r\n \
    \ using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\
    \n    return {xc + yc, xs + ys, min(xm, ym)};\r\n  }\r\n  static constexpr X unit\
    \ = X({0, 0, INF});\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_cntsummin.hpp
  requiredBy:
  - alg/lazy_cntsummin_add.hpp
  timestamp: '2022-04-09 22:00:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_cntsummin.hpp
layout: document
redirect_from:
- /library/alg/monoid_cntsummin.hpp
- /library/alg/monoid_cntsummin.hpp.html
title: alg/monoid_cntsummin.hpp
---
