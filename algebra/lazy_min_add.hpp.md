---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/group_add.hpp
    title: algebra/group_add.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/monoid_min.hpp
    title: algebra/monoid_min.hpp
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
  bundledCode: "#line 2 \"algebra/group_add.hpp\"\ntemplate <class X, X ZERO = X(0)>\r\
    \nstruct AddGroup {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return n * x; }\r\n  static constexpr X unit = ZERO;\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 1 \"algebra/monoid_min.hpp\"\n\
    template <class X, X INF>\r\nstruct MinMonoid {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit = INF;\r\n};\r\n#line 3 \"algebra/lazy_min_add.hpp\"\
    \n\r\ntemplate <typename E, E INF>\r\nstruct Min_Add_Lazy {\r\n  using MX = MinMonoid<E,\
    \ INF>;\r\n  using MA = AddGroup<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { \r\n    return x + a;\r\n\
    \  }\r\n};\n"
  code: "#include \"algebra/group_add.hpp\"\r\n#include \"algebra/monoid_min.hpp\"\
    \r\n\r\ntemplate <typename E, E INF>\r\nstruct Min_Add_Lazy {\r\n  using MX =\
    \ MinMonoid<E, INF>;\r\n  using MA = AddGroup<E>;\r\n  using X_structure = MX;\r\
    \n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\n  using\
    \ A = typename MA::value_type;\r\n  static constexpr X act(const X &x, const A\
    \ &a) { \r\n    return x + a;\r\n  }\r\n};"
  dependsOn:
  - algebra/group_add.hpp
  - algebra/monoid_min.hpp
  isVerificationFile: false
  path: algebra/lazy_min_add.hpp
  requiredBy: []
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
documentation_of: algebra/lazy_min_add.hpp
layout: document
redirect_from:
- /library/algebra/lazy_min_add.hpp
- /library/algebra/lazy_min_add.hpp.html
title: algebra/lazy_min_add.hpp
---
