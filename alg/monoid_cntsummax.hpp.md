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
  bundledCode: "#line 1 \"alg/monoid_cntsummax.hpp\"\nstruct Monoid_CntSumMax {\r\n\
    \  static constexpr ll INF = 1LL << 60;\r\n  using value_type = tuple<ll, ll,\
    \ ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n    auto [xc,\
    \ xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\n    return {xc + yc, xs + ys,\
    \ max(xm, ym)};\r\n  }\r\n  static constexpr X unit = X({0, 0, -INF});\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  code: "struct Monoid_CntSumMax {\r\n  static constexpr ll INF = 1LL << 60;\r\n \
    \ using value_type = tuple<ll, ll, ll>;\r\n  using X = value_type;\r\n  static\
    \ X op(X x, X y) {\r\n    auto [xc, xs, xm] = x;\r\n    auto [yc, ys, ym] = y;\r\
    \n    return {xc + yc, xs + ys, max(xm, ym)};\r\n  }\r\n  static constexpr X unit\
    \ = X({0, 0, -INF});\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_cntsummax.hpp
  requiredBy: []
  timestamp: '2022-02-03 13:42:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_cntsummax.hpp
layout: document
redirect_from:
- /library/alg/monoid_cntsummax.hpp
- /library/alg/monoid_cntsummax.hpp.html
title: alg/monoid_cntsummax.hpp
---
