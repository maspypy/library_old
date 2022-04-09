---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_minmax_add.hpp
    title: alg/lazy_minmax_add.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_minmax.hpp\"\ntemplate <class X=long long, X\
    \ INF=1LL<<60>\r\nstruct Monoid_MinMax {\r\n  using P = pair<X, X>;\r\n  using\
    \ value_type = P;\r\n  static constexpr P op(const P x, const P y) noexcept {\
    \ return {min(x.fi, y.fi), max(x.se, y.se)}; }\r\n  static constexpr P unit =\
    \ P({INF, -INF});\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class X=long long, X INF=1LL<<60>\r\nstruct Monoid_MinMax {\r\n\
    \  using P = pair<X, X>;\r\n  using value_type = P;\r\n  static constexpr P op(const\
    \ P x, const P y) noexcept { return {min(x.fi, y.fi), max(x.se, y.se)}; }\r\n\
    \  static constexpr P unit = P({INF, -INF});\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_minmax.hpp
  requiredBy:
  - alg/lazy_minmax_add.hpp
  timestamp: '2022-03-07 00:57:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_minmax.hpp
layout: document
redirect_from:
- /library/alg/monoid_minmax.hpp
- /library/alg/monoid_minmax.hpp.html
title: alg/monoid_minmax.hpp
---
