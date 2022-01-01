---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebra/lazy_max_set.hpp
    title: algebra/lazy_max_set.hpp
  - icon: ':warning:'
    path: algebra/lazy_min_set.hpp
    title: algebra/lazy_min_set.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algebra/monoid_set.hpp\"\ntemplate<typename E, E none_val\
    \ = E(-1)>\r\nstruct SetMonoid {\r\n  using value_type = E;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) {\r\n    return (y==none_val ? x : y);\r\n  }\r\n  static\
    \ constexpr X unit = none_val;\r\n  bool commute = false;\r\n};\n"
  code: "template<typename E, E none_val = E(-1)>\r\nstruct SetMonoid {\r\n  using\
    \ value_type = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) {\r\n\
    \    return (y==none_val ? x : y);\r\n  }\r\n  static constexpr X unit = none_val;\r\
    \n  bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algebra/monoid_set.hpp
  requiredBy:
  - algebra/lazy_max_set.hpp
  - algebra/lazy_min_set.hpp
  timestamp: '2022-01-01 19:42:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebra/monoid_set.hpp
layout: document
redirect_from:
- /library/algebra/monoid_set.hpp
- /library/algebra/monoid_set.hpp.html
title: algebra/monoid_set.hpp
---
