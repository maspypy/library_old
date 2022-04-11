---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':warning:'
    path: alg/monoid_cntsummin.hpp
    title: alg/monoid_cntsummin.hpp
  _extendedRequiredBy: []
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
    \ constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/group_add.hpp\"\ntemplate\
    \ <class X, X ZERO = X(0)>\r\nstruct Group_Add {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return n * x; }\r\n  static constexpr\
    \ X unit = ZERO;\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"\
    alg/lazy_cntsummin_add.hpp\"\n\r\nstruct Lazy_CntSumMin_Add {\r\n  static constexpr\
    \ ll INF = 1LL<<60;\r\n  using MX = Monoid_CntSumMin;\r\n  using MA = Group_Add<ll>;\r\
    \n  using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X& x, const A& a) {\r\n    auto [xc, xs, xm] = x;\r\n    return\
    \ {xc, xs + xc * a, xm + a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid_cntsummin.hpp\"\r\n#include \"alg/group_add.hpp\"\r\
    \n\r\nstruct Lazy_CntSumMin_Add {\r\n  static constexpr ll INF = 1LL<<60;\r\n\
    \  using MX = Monoid_CntSumMin;\r\n  using MA = Group_Add<ll>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X& x,\
    \ const A& a) {\r\n    auto [xc, xs, xm] = x;\r\n    return {xc, xs + xc * a,\
    \ xm + a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid_cntsummin.hpp
  - alg/group_add.hpp
  isVerificationFile: false
  path: alg/lazy_cntsummin_add.hpp
  requiredBy: []
  timestamp: '2022-04-09 22:00:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_cntsummin_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_cntsummin_add.hpp
- /library/alg/lazy_cntsummin_add.hpp.html
title: alg/lazy_cntsummin_add.hpp
---
