---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/max_set_lazy.hpp
    title: algebra/max_set_lazy.hpp
  - icon: ':heavy_check_mark:'
    path: algebra/min_set_lazy.hpp
    title: algebra/min_set_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/setmonoid.hpp\"\ntemplate<typename E, E none_val\
    \ = E(-1)>\r\nstruct SetMonoid {\r\n  using value_type = E;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    return (y==none_val ? x : y);\r\n  }\r\n  static\
    \ constexpr X unit = none_val;\r\n  bool commute = false;\r\n};\n"
  code: "template<typename E, E none_val = E(-1)>\r\nstruct SetMonoid {\r\n  using\
    \ value_type = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n\
    \    return (y==none_val ? x : y);\r\n  }\r\n  static constexpr X unit = none_val;\r\
    \n  bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/setmonoid.hpp
  requiredBy:
  - algebra/min_set_lazy.hpp
  - algebra/max_set_lazy.hpp
  timestamp: '2022-01-01 19:23:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
documentation_of: algebra/setmonoid.hpp
layout: document
redirect_from:
- /library/algebra/setmonoid.hpp
- /library/algebra/setmonoid.hpp.html
title: algebra/setmonoid.hpp
---
