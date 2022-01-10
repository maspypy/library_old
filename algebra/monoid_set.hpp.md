---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_cntsum_set.hpp
    title: algebra/lazy_cntsum_set.hpp
  - icon: ':warning:'
    path: algebra/lazy_max_set.hpp
    title: algebra/lazy_max_set.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/lazy_min_set.hpp
    title: algebra/lazy_min_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D_dualsegtree.test.cpp
    title: test/aoj/DSL_2_D_dualsegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
    title: test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_set.hpp\"\ntemplate <typename E, E none_val>\r\
    \nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static constexpr\
    \ X unit = none_val;\r\n  static constexpr bool commute = false;\r\n};\n"
  code: "template <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit = none_val;\r\n  static constexpr bool\
    \ commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_set.hpp
  requiredBy:
  - algebra/lazy_cntsum_set.hpp
  - algebra/lazy_max_set.hpp
  - algebra/lazy_min_set.hpp
  timestamp: '2022-01-01 23:47:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
  - test/aoj/DSL_2_D_dualsegtree.test.cpp
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
documentation_of: algebra/monoid_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_set.hpp
- /library/algebra/monoid_set.hpp.html
title: algebra/monoid_set.hpp
---