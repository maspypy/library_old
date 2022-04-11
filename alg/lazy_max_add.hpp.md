---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':warning:'
    path: alg/monoid_max.hpp
    title: alg/monoid_max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct Group_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_max.hpp\"\ntemplate\
    \ <class X=long long, X INF=1LL<<60>\r\nstruct Monoid_Max {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\r\n  static constexpr X unit = -INF;\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 3 \"alg/lazy_max_add.hpp\"\n\r\ntemplate <typename E,\
    \ E INF>\r\nstruct Lazy_Min_Add {\r\n  using MX = Monoid_Max<E, INF>;\r\n  using\
    \ MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure = MA;\r\
    \n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { \r\n    return max(MX::unit,\
    \ x + a);\r\n  }\r\n};\r\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/monoid_max.hpp\"\r\n\r\n\
    template <typename E, E INF>\r\nstruct Lazy_Min_Add {\r\n  using MX = Monoid_Max<E,\
    \ INF>;\r\n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) { \r\n \
    \   return max(MX::unit, x + a);\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/group_add.hpp
  - alg/monoid_max.hpp
  isVerificationFile: false
  path: alg/lazy_max_add.hpp
  requiredBy: []
  timestamp: '2022-04-09 22:00:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/lazy_max_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_max_add.hpp
- /library/alg/lazy_max_add.hpp.html
title: alg/lazy_max_add.hpp
---
