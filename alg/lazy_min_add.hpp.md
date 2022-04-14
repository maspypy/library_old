---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/group_add.hpp
    title: alg/group_add.hpp
  - icon: ':question:'
    path: alg/monoid_min.hpp
    title: alg/monoid_min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
    title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_add.hpp\"\ntemplate <class X>\r\nstruct Group_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ n * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 1 \"alg/monoid_min.hpp\"\ntemplate <class\
    \ X, X INF>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr\
    \ X unit() { return INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n\
    #line 3 \"alg/lazy_min_add.hpp\"\n\r\ntemplate <typename E, E INF>\r\nstruct Lazy_Min_Add\
    \ {\r\n  using MX = Monoid_Min<E, INF>;\r\n  using MA = Group_Add<E>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    return min(MX::unit(), x + a);\r\n  }\r\n};\n"
  code: "#include \"alg/group_add.hpp\"\r\n#include \"alg/monoid_min.hpp\"\r\n\r\n\
    template <typename E, E INF>\r\nstruct Lazy_Min_Add {\r\n  using MX = Monoid_Min<E,\
    \ INF>;\r\n  using MA = Group_Add<E>;\r\n  using X_structure = MX;\r\n  using\
    \ A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename\
    \ MA::value_type;\r\n  static constexpr X act(const X &x, const A &a) {\r\n  \
    \  return min(MX::unit(), x + a);\r\n  }\r\n};"
  dependsOn:
  - alg/group_add.hpp
  - alg/monoid_min.hpp
  isVerificationFile: false
  path: alg/lazy_min_add.hpp
  requiredBy: []
  timestamp: '2022-04-11 19:14:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
documentation_of: alg/lazy_min_add.hpp
layout: document
redirect_from:
- /library/alg/lazy_min_add.hpp
- /library/alg/lazy_min_add.hpp.html
title: alg/lazy_min_add.hpp
---
