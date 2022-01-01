---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebra/minmonoid.hpp
    title: algebra/minmonoid.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/setmonoid.hpp
    title: algebra/setmonoid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/minmonoid.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ MinMonoid {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit = INF;\r\
    \n};\r\n#line 1 \"algebra/setmonoid.hpp\"\ntemplate<typename E, E none_val = E(-1)>\r\
    \nstruct SetMonoid {\r\n  using value_type = E;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) {\r\n    return (y==none_val ? x : y);\r\n  }\r\n  static\
    \ constexpr X unit = none_val;\r\n  bool commute = false;\r\n};\n#line 3 \"algebra/min_set_lazy.hpp\"\
    \n\r\ntemplate <typename E, E INF, E none_val=-1>\r\nstruct Min_Set_Lazy {\r\n\
    \  using MX = MinMonoid<E, INF>;\r\n  using MA = SetMonoid<E, none_val>;\r\n \
    \ using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) { return (a==none_val ? x : a) ;}\r\n};\r\n"
  code: "#include \"algebra/minmonoid.hpp\"\r\n#include \"algebra/setmonoid.hpp\"\r\
    \n\r\ntemplate <typename E, E INF, E none_val=-1>\r\nstruct Min_Set_Lazy {\r\n\
    \  using MX = MinMonoid<E, INF>;\r\n  using MA = SetMonoid<E, none_val>;\r\n \
    \ using X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename\
    \ MX::value_type;\r\n  using A = typename MA::value_type;\r\n  static constexpr\
    \ X act(const X &x, const A &a) { return (a==none_val ? x : a) ;}\r\n};\r\n"
  dependsOn:
  - algebra/minmonoid.hpp
  - algebra/setmonoid.hpp
  isVerificationFile: false
  path: algebra/min_set_lazy.hpp
  requiredBy: []
  timestamp: '2022-01-01 19:34:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
documentation_of: algebra/min_set_lazy.hpp
layout: document
redirect_from:
- /library/algebra/min_set_lazy.hpp
- /library/algebra/min_set_lazy.hpp.html
title: algebra/min_set_lazy.hpp
---
